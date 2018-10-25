//
// Created by gabriel on 21/10/18.
//

#ifndef LIB_LIBRARY_H 
#define LIB_LIBRARY_H __declspec(dllexport)

//typedef void(__stdcall * DebugCallback) (const char * str);
//DebugCallback gDebugCallback;

#include "Maps/Djikstra.h"

extern "C" {
    //Prueba
    LIB_LIBRARY_H int Add(int a, int b);
    //Funciones de Mapa Djikstra
	LIB_LIBRARY_H Djikstra* getMap(int level);
	LIB_LIBRARY_H void SendPositions(Djikstra map, int xi, int yi, int xf, int yf);
	LIB_LIBRARY_H void SendListAdder(Djikstra map, void(*action)(int x, int y), void(*boolean)(bool m));
	//Funciones de Mapa
		//Retorne mapa a*
		//Recibe posiciones (aStar map, int xi, int yi, int xf, int yf)
		//Manda lista de posiciones (aStar map, void(*action)(int x, int y), void(*boolean)(bool m))

}
//void hello();

class library
{
public:
	
	library();
	~library();
	
};


#endif //LIB_LIBRARY_H
