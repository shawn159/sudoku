#ifndef CALCULATER_H
#define CALCULATER_H
#include "GameData.h"

class Calculater{
private:
	GameData* gameData_Calculater;
public:
	Calculater();
	int checkNumber(int row, int column, int number);
	int checkFinish();
};

#endif