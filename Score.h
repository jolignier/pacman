#ifndef SCORE_H
#define SCORE_H

#include <stdlib.h>

using namespace std;

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
