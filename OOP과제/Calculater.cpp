#include <iostream>
#include "Calculater.h"
#include "GameData.h"
using namespace std;

Calculater::Calculater(){
	gameData_Calculater = GameData::getInstance();
}

int Calculater::checkNumber(int row, int column, int number){
	int check = 0;
	for (int i = 0; i < 9; i++){
		if ((gameData_Calculater->getElement(i, column) == number) || (gameData_Calculater->getElement(row, i) == number)){
			check = 1;
			break;
		}
	}
	if (check != 1){
		for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++){
			for (int j = (column / 3) * 3; j < (column / 3) * 3 + 3; j++){
				if ((i != row) && (j != column)){
					if (gameData_Calculater->getElement(i, j) == number){
						check = 1;
						i += 3;
						break;
					}
				}
			}
		}
	}

	return check;
}

int Calculater::checkFinish(){
	int check = 1;
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (gameData_Calculater->getElement(i, j) == 0){
				check = 0;
				i += 9;
				break;
			}
		}
	}

	return check;
}