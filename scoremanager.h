#ifndef SCORE_H
#define SCORE_H

#include <stdlib.h>
#include <QString>
#include <QList>
#include <QStringListModel>
#include <QtNetwork/QNetworkReply>

using namespace std;

class ScoreManager : public QObject
{
    Q_OBJECT
private:
    QList<QPair<int, QString>>* scores;
    int currentScore;
    const QString api_token = "8a3dbea6-cf11-486f-a68e-e1af2a99c767";
    QNetworkAccessManager networkManager;

    void retrieveScores();

public slots:
    void onGetResult(QNetworkReply* reply);

signals:
    void scoresRetrieved();
    void currentScoreChanged();

public:
    explicit ScoreManager(QObject *parent = 0);

    QList<QPair<int, QString>>* getScores();
    QList<QPair<int, QString>>* getTop10();
    QPair<int, QString> getHighestScore();

    void saveCurrentScore(QString name);

	int getCurrentScore();
    void addPoints(int points);

};

#endif
