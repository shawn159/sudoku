#ifndef GAMEDATA_H
#define GAMEDATA_H

class GameData{
private:
	int mapData_gameData[9][9];
	static GameData* instance;
public:
	static GameData* getInstance();
	
	void setElement(int row_gameData, int column_gameData, int number_gameData);
	int getElement(int row_gameData, int column_gameData);
	void setMap();
};

#endif