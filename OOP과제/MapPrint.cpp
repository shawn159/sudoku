#include <iostream>
#include "MapPrint.h"
#include "GameData.h"
using namespace std;

MapPrint::MapPrint(){
	gameData_MapPrint = GameData::getInstance();
}

void MapPrint::printingMap(){
	cout << "忙式成式成式成式成式成式成式成式成式忖" << endl;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 9; j++){
			if (gameData_MapPrint->getElement(i, j) == 0){
				cout << "弛 " << " ";
			}
			else{
				cout << "弛 " << gameData_MapPrint->getElement(i, j);
			}
		}
		cout << "弛" << endl;
		cout << "戍式托式托式托式托式托式托式托式托式扣" << endl;
	}
	for (int i = 0; i < 9; i++){
		if (gameData_MapPrint->getElement(8, i) == 0){
			cout << "弛 " << " ";
		}
		else{
			cout << "弛 " << gameData_MapPrint->getElement(8, i);
		}
	}
	cout << "弛" << endl;
	cout << "戌式扛式扛式扛式扛式扛式扛式扛式扛式戎" << endl;

}
