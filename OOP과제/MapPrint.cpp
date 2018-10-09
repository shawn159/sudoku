#include <iostream>
#include "MapPrint.h"
#include "GameData.h"
using namespace std;

MapPrint::MapPrint(){
	gameData_MapPrint = GameData::getInstance();
}

void MapPrint::printingMap(){
	cout << "��������������������������������������" << endl;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 9; j++){
			if (gameData_MapPrint->getElement(i, j) == 0){
				cout << "�� " << " ";
			}
			else{
				cout << "�� " << gameData_MapPrint->getElement(i, j);
			}
		}
		cout << "��" << endl;
		cout << "��������������������������������������" << endl;
	}
	for (int i = 0; i < 9; i++){
		if (gameData_MapPrint->getElement(8, i) == 0){
			cout << "�� " << " ";
		}
		else{
			cout << "�� " << gameData_MapPrint->getElement(8, i);
		}
	}
	cout << "��" << endl;
	cout << "��������������������������������������" << endl;

}
