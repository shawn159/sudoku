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
			cout << "�Է��� ��� ���� �Է��� �ּ��� (��:2 3) : ";
			cin >> row >> column;
			cout << endl;
			if (row<1 || row>9 || column<1 || column>9){
				cout << "��� ���� 1���� 9������ ���� �Դϴ�." << endl;
			}
			else{
				checkNumber = 0;
			}
		}
		checkNumber = 1;
		while (checkNumber){
			cout << "�Է��� ���ڸ� �Է����ּ��� : ";
			cin >> number;
			cout << endl;
			if (number<1 || number>9){
				cout << "�Է��� ���ڴ� 1���� 9������ ���� �Դϴ�." << endl;
			}
			else{
				checkNumber = 0;
			}
		}
		if (gameData_Main->getElement(row-1, column-1) != 0){
			cout << "���� �����Ͻðڽ��ϱ�?? (y/n) : ";
			cin >> decision;
			cout << endl;
		}
		if (decision == 'n'){
			goto getNumber;
		}
		if (calculater_Main.checkNumber(row-1, column-1, number) == 1){
			cout << "�Է��Ͻ� ���ڿ� ��ġ�� ���ڰ� �̹� �־� �Է� �Ұ��մϴ�." << endl;
			goto getNumber;
		}
		else{
			gameData_Main->setElement(row-1, column-1, number);
		}
		if (calculater_Main.checkFinish() == 1){
			cout << "������ �ϼ��ϼ̽��ϴ�!!�����մϴ�." << endl << "�����Ͻ÷��� �ƹ�Ű�� �Է����ּ���.";
			cin >> end;
			gameEnd = 0;
		}
		system("cls");
	}

	return 0;
}