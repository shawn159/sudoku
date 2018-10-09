#ifndef MAPPRINT_H
#define MAPPRINT_H
#include "GameData.h"

class MapPrint{
private:
	GameData* gameData_MapPrint;

public:
	MapPrint();
	void printingMap();
};

#endif