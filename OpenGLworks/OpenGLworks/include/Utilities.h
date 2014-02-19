#ifndef _UTILITIES_H_
#define _UTILITIES_H_

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
			float U, V, W; 
		};};
	bool operator == (const Vertex& rhs){
		return (X == rhs.X && Y == rhs.Y && Z == rhs.Z
				&& R == rhs.R && G == rhs.G && B == rhs.B && A == rhs.A
				&& U == rhs.U && V == rhs.V && W == rhs.W);
	}};

struct UV
{
	float Umin, Vmin, Umax, Vmax;
};

extern Matrix4 * Ortho;
void Orthographic(float a_fLeft, float a_fRight, float a_fTop, float a_fBottom, 
				  float a_fNear, float a_fFar, Matrix4 * mat);

#endif