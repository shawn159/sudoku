#include <iostream>
#include <fstream>
#include "GameData.h"
using namespace std;

GameData* GameData::instance = NULL;

GameData* GameData::getInstance(){
	if (instance == NULL){
		instance = new GameData();
	}
	return instance;
}

void GameData::setElement(int row_gameData, int column_gameData, int number_gameData){
	mapData_gameData[row_gameData][column_gameData] = number_gameData;
}

int GameData::getElement(int row_gameData, int column_gameData){
	return mapData_gameData[row_gameData][column_gameData];
}

void GameData::setMap(){
	ifstream read;
	read.open("sdc.txt");
	char temp1[10 * sizeof(char)] = { '\0' };
	char temp2[10 * sizeof(char)] = { '\0' };
	char temp3[10 * sizeof(char)] = { '\0' };
	char temp4[10 * sizeof(char)] = { '\0' };
	char temp5[10 * sizeof(char)] = { '\0' };
	char temp6[10 * sizeof(char)] = { '\0' };
	char temp7[10 * sizeof(char)] = { '\0' };
	char temp8[10 * sizeof(char)] = { '\0' };
	char temp9[10 * sizeof(char)] = { '\0' };
	if (read.good()) {
		while (!read.eof()) {
			read.getline(temp1, sizeof(read));
			read.getline(temp2, sizeof(read));
			read.getline(temp3, sizeof(read));
			read.getline(temp4, sizeof(read));
			read.getline(temp5, sizeof(read));
			read.getline(temp6, sizeof(read));
			read.getline(temp7, sizeof(read));
			read.getline(temp8, sizeof(read));
			read.getline(temp9, sizeof(read));
		}
		for (int j = 0; j < 9; j++){
			mapData_gameData[0][j] = temp1[j] - '0';
			mapData_gameData[1][j] = temp2[j] - '0';
			mapData_gameData[2][j] = temp3[j] - '0';
			mapData_gameData[3][j] = temp4[j] - '0';
			mapData_gameData[4][j] = temp5[j] - '0';
			mapData_gameData[5][j] = temp6[j] - '0';
			mapData_gameData[6][j] = temp7[j] - '0';
			mapData_gameData[7][j] = temp8[j] - '0';
			mapData_gameData[8][j] = temp9[j] - '0';
		}
	}
	else {
		cout << "파일 불러오기를 실패하였습니다." << endl;
	}
	read.close();
}


