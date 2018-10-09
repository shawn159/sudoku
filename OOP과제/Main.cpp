#include <iostream>
#include <process.h>
#include <Windows.h>
#include "MapPrint.h"
#include "GameData.h"
#include "Calculater.h"
using namespace std;

int main(){
	int gameEnd = 1;
	int row, column, number;
	char decision=NULL;
	GameData* gameData_Main = GameData::getInstance();
	MapPrint mapPrint_Main;
	Calculater calculater_Main;
	gameData_Main->setMap();
	
	while (gameEnd){
		mapPrint_Main.printingMap();
		cout << endl << endl;
		getNumber:
		int checkNumber = 1;
		char end = NULL;
		decision = NULL;
		while (checkNumber){
			cout << "입력할 행과 열을 입력해 주세요 (예:2 3) : ";
			cin >> row >> column;
			cout << endl;
			if (row<1 || row>9 || column<1 || column>9){
				cout << "행과 열은 1부터 9사이의 정수 입니다." << endl;
			}
			else{
				checkNumber = 0;
			}
		}
		checkNumber = 1;
		while (checkNumber){
			cout << "입력할 숫자를 입력해주세요 : ";
			cin >> number;
			cout << endl;
			if (number<1 || number>9){
				cout << "입력할 숫자는 1부터 9사이의 숫자 입니다." << endl;
			}
			else{
				checkNumber = 0;
			}
		}
		if (gameData_Main->getElement(row-1, column-1) != 0){
			cout << "값을 변경하시겠습니까?? (y/n) : ";
			cin >> decision;
			cout << endl;
		}
		if (decision == 'n'){
			goto getNumber;
		}
		if (calculater_Main.checkNumber(row-1, column-1, number) == 1){
			cout << "입력하신 숫자와 겹치는 숫자가 이미 있어 입력 불가합니다." << endl;
			goto getNumber;
		}
		else{
			gameData_Main->setElement(row-1, column-1, number);
		}
		if (calculater_Main.checkFinish() == 1){
			cout << "스도쿠를 완성하셨습니다!!축합합니다." << endl << "종료하시려면 아무키를 입력해주세요.";
			cin >> end;
			gameEnd = 0;
		}
		system("cls");
	}

	return 0;
}