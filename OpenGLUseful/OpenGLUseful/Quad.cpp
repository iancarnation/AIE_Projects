/////////////////////////////////////////////////////////////////////////////////////////////
// Quad.cpp
// makes quads (as triangle strips)
/////////////////////////////////////////////////////////////////////////////////////////////

#include "Quad.h"
#include <stdlib.h>
#include <time.h>

Quad::Quad()
{
	srand(time(NULL));
	float randStartX = (rand()%100) / 100;
	float randStartY = (rand()%100) / 100;
	float randOffsetX = (rand()%100) / 100;
	float randOffsetY = (rand()%100) / 100;


}