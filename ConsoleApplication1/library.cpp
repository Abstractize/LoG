//
// Created by gabriel on 21/10/18.
//

#include "library.h"
#include "Maps/Map.h"
#include "Maps/Djikstra.h"
//#include "DebugCPP.h"

#include <iostream>

//List<int> PosList;





LIB_LIBRARY_H int Add(int a, int b) {
    return a + b;
}

//Funciones Djikstra
LIB_LIBRARY_H Djikstra * getMap(int level)
{
	std::cout << "Djikstra created" << std::endl;
	return new Djikstra();
}

LIB_LIBRARY_H void SendListAdder(Djikstra map, void(*action)(int x, int y), void(*boolean)(bool m))
{
	return map.sendlist(action,boolean);
}
LIB_LIBRARY_H void SendPositions(Djikstra map, int xi, int yi, int xf, int yf){
	std::cout << "Positions recived" << std::endl;
	return map.getPositions(xi, yi, xf, yf);
	
}


library::library()
{
}


library::~library()
{
}



