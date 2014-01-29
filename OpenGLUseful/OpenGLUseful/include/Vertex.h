#ifndef _VERTEX_
#define _VERTEX_

#include "MathLibrary.h"

struct Vertex
{	union
	{	struct
		{	Vector3 Pos;
			Vector4 Color;
			Vector3 UV;};
		struct
		{	float X, Y, Z;
			float R, G, B, A;
			float U, V, W; // n is dummy spot.. only need 2 numbers... is vector3 class needed?
		};};
	bool operator == (const Vertex& rhs){
		return (X == rhs.X && Y == rhs.Y && Z == rhs.Z
				&& R == rhs.R && G == rhs.G && B == rhs.B && A == rhs.A
				&& U == rhs.U && V == rhs.V && W == rhs.W);
	}};

#endif