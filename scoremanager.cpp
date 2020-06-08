#include "scoremanager.h"

#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>


ScoreManager::ScoreManager(QObject *parent):
    QObject(parent)
{
    this->scores = new QList<QPair<int, QString>>();
    this->retrieveScores();
    this->currentScore = 0;

    connect(this, SIGNAL(scoresRetrieved()), parent, SLOT(updateScores()));
}

QList<QPair<int, QString>>* ScoreManager::getScores() {
    return this->scores;
}

QList<QPair<int, QString>>* ScoreManager::getTop10() {
    QList<QPair<int, QString>>* top10 = new QList<QPair<int, QString>>();

    for (int i=0; i<10; i++){
        if (this->scores->size() > i)
            top10->append(this->scores->at(i));
    }
    return top10;
}

QPair<int, QString> ScoreManager::getHighestScore() {
    return scores->at(0);
}

void ScoreManager::saveCurrentScore(QString name) {
    bool inserted = false;
    for (int i=0; i<scores->size(); i++) {
        if (scores->at(i).first > currentScore) {
            scores->insert(i, QPair<int, QString>(currentScore,name));
            inserted = true;
        }
    }
    if (!inserted)
        scores->append(QPair<int, QString>(currentScore,name));

    QUrl url("http://newtoncat.ddns.net/pacman/post.php?api=" + this->api_token);
    QNetworkRequest request;
    request.setUrl(url);

    QByteArray data;
    data.append("score=" + QByteArray::number(currentScore));
    data.append("&name="+ name);
    data.append("&api="+ api_token);

    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    networkManager.post(request,data);
}

int ScoreManager::getCurrentScore() {
	return this->currentScore;
}

void ScoreManager::addPoints(int points){
    currentScore += points;
    emit currentScoreChanged();
}

void ScoreManager::retrieveScores() {

    this->scores->clear();

    QUrl url("http://newtoncat.ddns.net/pacman/get.php?api=" + this->api_token);
    QNetworkRequest request;
    request.setUrl(url);
    QNetworkReply* reply = networkManager.get(request);

    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onGetResult(QNetworkReply*)));
}

void ScoreManager::onGetResult(QNetworkReply* reply){

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QJsonDocument document = QJsonDocument::fromJson(data);

        QJsonArray array = document.object().value("scores").toArray();
        foreach(const QJsonValue &v, array){
            QString score = v.toObject().value("score").toString();
            int score_int = score.toInt();
            QString name = v.toObject().value("name").toString();

            this->scores->append(QPair<int,QString>(score_int, name));
        }
    } else {
        QMessageBox messageBox;
        messageBox.critical(0, "An error occured while retrieving scores", reply->errorString());
    }
    emit scoresRetrieved();
}
