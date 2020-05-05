#ifndef SCORE_H
#define SCORE_H

class Score {

private:
	int scores;
	int currentScore;

public:
	Score();

	void getScores();

	void getTop10();

	void getHighestScore();

	void saveScore();

	int getCurrentScore();
};

#endif
