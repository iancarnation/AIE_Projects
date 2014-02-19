#include "Utilities.h"

Matrix4 * Ortho;
void Orthographic(float a_fLeft, float a_fRight, float a_fTop, float a_fBottom, 
				  float a_fNear, float a_fFar, Matrix4 * mat)
{
	float deltaX = a_fRight - a_fLeft;
	float deltaY = a_fTop - a_fBottom;
	float deltaZ = a_fNear - a_fFar;

/*  2/dx 0    0    lr
	0    2/dy 0    bt
	0    0    2/dz nf
	0    0    0    1  */

mat->m11 = 2.f / deltaX;
mat->m21 = 0.f;
mat->m31 = 0.f;
mat->m41 = 0.f;
mat->m12 = 0.f;
mat->m22 = 2.f / deltaY;
mat->m32 = 0.f;
mat->m42 = 0.f;
mat->m13 = 0.f;
mat->m23 = 0.f;
mat->m33 = 2.f / deltaZ;
mat->m43 = 0.f;
mat->m14 = ((a_fLeft + a_fRight)/(a_fLeft - a_fRight));
mat->m24 = ((a_fBottom + a_fTop)/(a_fBottom - a_fTop));
mat->m34 = (-(a_fNear + a_fFar)/(a_fFar - a_fNear));
mat->m44 = 1.f;
}
