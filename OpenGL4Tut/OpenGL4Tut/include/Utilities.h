#ifndef _UTIL_H_
#define _UTIL_H_
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <FreeImage.h>

//Terry's Math lib
#include <TerrehByteMath.h>
//other helper functions
#include "GLLog.h"
#include "TextFileReader.h"


#include <string>
#include <queue>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <assert.h>
#include <functional>


struct Vertex
{
	union
	{
		struct 
		{
			tbyte::Vector3 Pos;
			tbyte::Vector4 Color;
			tbyte::Vector2 UV;
		};
		
		struct
		{
			float X, Y, Z, W;
			float R, G, B, A;
			float U, V;
		};
	};
	

	bool operator == (const Vertex& rhs)
	{
		return (X == rhs.X && Y == rhs.Y && Z == rhs.Z && W == rhs.W && U == rhs.U && V == rhs.V && R == rhs.R && G == rhs.G && B == rhs.B && A == rhs.A );
	}
};

//////////////////////////////////////////////////////////////////////////
// A 4D matrix class
//////////////////////////////////////////////////////////////////////////
class mat4
{
public:
	// warning 4201 can be ignored as unnamed structs/unions is allowed in this case
	union
	{
		float mm[4][4];
		float m[16];
		struct  
		{
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		struct  
		{
			tbyte::Vector4 row0, row1, row2, row3;
		};
	};

	mat4() {}
	mat4(float a, float b, float c, float d,
		float e, float f, float g, float h,
		float i, float j, float k, float l,
		float m, float n, float o, float p)
		: _11(a), _12(b), _13(c), _14(d),
		_21(e), _22(f), _23(g), _24(h),
		_31(i), _32(j), _33(k), _34(l),
		_41(m), _42(n), _43(o), _44(p)
	{

	}
	~mat4() {}
	
	void SetFrame(const tbyte::Vector4& position, const tbyte::Vector4& forward, const tbyte::Vector4& up)
	{
		tbyte::Vector4 vForward = forward;
		vForward.Normalise();

		tbyte::Vector4 vRight = up.Cross(vForward);
		vRight.Normalise();

		tbyte::Vector4 vUp = vForward.Cross(vRight);
		vUp.Normalise();
		
		row0 = vRight;
		row1 = vUp;
		row2 = vForward;
		row3 = position;
	}

	mat4 ToViewMatrix()
	{
		mat4 view;
		
		view._11 = row0.m_fX; 
		view._21 = row0.m_fY; 
		view._31 = row0.m_fZ; 
		view._41 = -(row0.Dot(row3));   

		view._12 = row1.m_fX;
		view._22 = row1.m_fY;
		view._32 = row1.m_fZ;
		view._42 = -(row1.Dot(row3));  

		view._13 = row2.m_fX; 
		view._23 = row2.m_fY; 
		view._33 = row2.m_fZ; 
		view._43 = -(row2.Dot(row3));   

		view._14 = 0.0f;
		view._24 = 0.0f;
		view._34 = 0.0f;
		view._44 = 1.0f;

		return view;
	}
	
	void ViewLookAt(const tbyte::Vector4& eye, const tbyte::Vector4& to, const tbyte::Vector4& up)
	{
		tbyte::Vector4 vForward = to - eye;
		vForward.Normalise();

		tbyte::Vector4 vLeft = up.Cross(vForward);
		vLeft.Normalise();

		tbyte::Vector4 vUp = vForward.Cross(vLeft);
		
		_11 = vLeft.m_fX; 
		_21 = vLeft.m_fY; 
		_31 = vLeft.m_fZ; 
		_41 = -(vLeft.Dot(eye));   

		_12 = vUp.m_fX;
		_22 = vUp.m_fY;
		_32 = vUp.m_fZ;
		_42 = -(vUp.Dot(eye));  

		_13 = vForward.m_fX; 
		_23 = vForward.m_fY; 
		_33 = vForward.m_fZ; 
		_43 = -(vForward.Dot(eye));   

		_14 = 0.0f;
		_24 = 0.0f;
		_34 = 0.0f;
		_44 = 1.0f;
	}
	
	void Orthographic(float a_fLeft, float a_fRight, float a_fTop, float a_fBottom, float a_fNear, float a_fFar)
	{
		float       deltaX = a_fRight - a_fLeft;
		float       deltaY = a_fTop - a_fBottom;
		float       deltaZ = a_fFar - a_fNear;

		_11 = 2.f / deltaX;
		_12 = 0.f;
		_13 = 0.f;
		_14 = 0.f;

		_21 = 0.f;
		_22 = 2.f / deltaY;
		_23 = 0.f;
		_24 = 0.f;

		_31 = 0.f;
		_32 = 0.f;
		_33 = -2.f / deltaZ;
		_34 = 0.f;

		_41 = -((a_fRight + a_fLeft)/deltaX);
		_42 = -((a_fTop + a_fBottom)/deltaY);
		_43 = -((a_fFar + a_fNear)/deltaZ);
		_44 = 1.f;
	}

	void Orthographic(float a_fWidth, float a_fHeight, float a_fNear, float a_fFar)
	{
		_11 = 2 / a_fWidth;
		_12 = 0;
		_13 = 0;
		_14 = 0;

		_21 = 0;
		_22 = 2 / a_fHeight;
		_23 = 0;
		_24 = 0;

		_31 = 0;
		_32 = 0;
		_33 = 1 / (a_fFar - a_fNear);
		_34 = 0;

		_41 = 0;
		_42 = 0;
		_43 = a_fNear / (a_fNear - a_fFar);
		_44 = 1;
	}

	void Perspective(float a_fUpFOV, float a_fAspectRatio, float a_fNear, float a_fFar)
	{
		float halfAngleRadians = 0.5f * a_fUpFOV;
		float cot = 1 / tanf(halfAngleRadians);

		_11 = cot / a_fAspectRatio;
		_12 = 0;
		_13 = 0;
		_14 = 0;

		_21 = 0;
		_22 = cot;
		_23 = 0;
		_24 = 0;

		_31 = 0;
		_32 = 0;
		_33 = a_fFar / (a_fFar - a_fNear);
		_34 = 1;

		_41 = 0;
		_42 = 0;
		_43 = a_fNear * a_fFar / (a_fNear - a_fFar);
		_44 = 0;
	}

	mat4 Transpose() const
	{
		return mat4(_11, _21, _31, _41,
					_12, _22, _32, _42,
					_13, _23, _33, _43,
					_14, _24, _34, _44);
	}

	void RotateX(float rad)
	{
		_11 = 1;	_12 = 0;			_13 = 0;			_14 = 0;
		_21 = 0;	_22 = cosf(rad);	_23 = -sinf(rad);	_24 = 0;
		_31 = 0;	_32 = sinf(rad);	_33 = cosf(rad);	_34 = 0;
		_41 = 0;	_42 = 0;			_43 = 0;			_44 = 1;
	}
	void RotateY(float rad)
	{
		_11 = cosf(rad);	_12 = 0;	_13 = -sinf(rad);	_14 = 0;
		_21 = 0;			_22 = 1;	_23 = 0;			_24 = 0;
		_31 = sinf(rad);	_32 = 0;	_33 = cosf(rad);	_34 = 0;
		_41 = 0;			_42 = 0;	_43 = 0;			_44 = 1;
	}
	void RotateZ(float rad)
	{
		_11 = cosf(rad);	_12 = -sinf(rad);	_13 = 0;	_14 = 0;
		_21 = sinf(rad);	_22 = cosf(rad);	_23 = 0;	_24 = 0;
		_31 = 0;			_32 = 0;			_33 = 1;	_34 = 0;
		_41 = 0;			_42 = 0;			_43 = 0;	_44 = 1;
	}
	void RotateAxis(float rad, const tbyte::Vector4& axis)
	{
		float fSin = sinf(rad), fCos = cosf(rad);

		float a = 1.0f - fCos;
		float ax = a * axis.m_fX;
		float ay = a * axis.m_fY;
		float az = a * axis.m_fZ;

		_11 = ax * axis.m_fX + fCos;
		_12 = ax * axis.m_fY + axis.m_fZ * fSin;
		_13 = ax * axis.m_fZ - axis.m_fY * fSin;
		_14 = 0;

		_21 = ay * axis.m_fX - axis.m_fZ * fSin;
		_22 = ay * axis.m_fY + fCos;
		_23 = ay * axis.m_fZ + axis.m_fX * fSin;
		_24 = 0;

		_31 = az * axis.m_fX + axis.m_fY * fSin;
		_32 = az * axis.m_fY - axis.m_fX * fSin;
		_33 = az * axis.m_fZ + fCos;
		_34 = 0;

		_41 = 0;
		_42 = 0;
		_43 = 0;
		_44 = 1;
	}
	void RotationEuler(float bank, float heading, float attitude)
	{
		mat4 x, y, z;
		x.RotateX(bank);
		y.RotateY(heading);
		z.RotateZ(attitude);

		*this = x * y * z;
	}

	void Scale( const tbyte::Vector2& v2Scale )
	{
		_11 = v2Scale.m_fX;	_12 =  0.0f;		_13 =  0.0f;		_14 = 0.0f;
		_21 =  0.0f;		_22 = v2Scale.m_fY; _23 =  0.0f;		_24 = 0.0f;
		_31 =  0.0f;		_32 =  0.0f;		_33 =  1.0f;		_34 = 0.0f;
		_41 =  0.0f;		_42 =  0.0f;		_43 =  0.0f;		_44 = 1.0f;
	}

	void Scale( const tbyte::Vector4& v4Scale )
	{
		_11 = v4Scale.m_fX;	_12 =  0.0f;		_13 =  0.0f;		_14 = 0.0f;
		_21 =  0.0f;		_22 =  v4Scale.m_fY;	_23 =  0.0f;		_24 = 0.0f;
		_31 =  0.0f;		_32 =  0.0f;		_33 =  v4Scale.m_fZ;	_34 = 0.0f;
		_41 =  0.0f;		_42 =  0.0f;		_43 =  0.0f;		_44 = 1.0f;
	}

	mat4 operator * (const mat4& a_rRHS) const
	{
		return mat4(	
			mm[0][0] * a_rRHS.mm[0][0] + mm[0][1] * a_rRHS.mm[1][0] + mm[0][2] * a_rRHS.mm[2][0] + mm[0][3] * a_rRHS.mm[3][0],
			mm[0][0] * a_rRHS.mm[0][1] + mm[0][1] * a_rRHS.mm[1][1] + mm[0][2] * a_rRHS.mm[2][1] + mm[0][3] * a_rRHS.mm[3][1],
			mm[0][0] * a_rRHS.mm[0][2] + mm[0][1] * a_rRHS.mm[1][2] + mm[0][2] * a_rRHS.mm[2][2] + mm[0][3] * a_rRHS.mm[3][2],
			mm[0][0] * a_rRHS.mm[0][3] + mm[0][1] * a_rRHS.mm[1][3] + mm[0][2] * a_rRHS.mm[2][3] + mm[0][3] * a_rRHS.mm[3][3],

			mm[1][0] * a_rRHS.mm[0][0] + mm[1][1] * a_rRHS.mm[1][0] + mm[1][2] * a_rRHS.mm[2][0] + mm[1][3] * a_rRHS.mm[3][0],
			mm[1][0] * a_rRHS.mm[0][1] + mm[1][1] * a_rRHS.mm[1][1] + mm[1][2] * a_rRHS.mm[2][1] + mm[1][3] * a_rRHS.mm[3][1],
			mm[1][0] * a_rRHS.mm[0][2] + mm[1][1] * a_rRHS.mm[1][2] + mm[1][2] * a_rRHS.mm[2][2] + mm[1][3] * a_rRHS.mm[3][2],
			mm[1][0] * a_rRHS.mm[0][3] + mm[1][1] * a_rRHS.mm[1][3] + mm[1][2] * a_rRHS.mm[2][3] + mm[1][3] * a_rRHS.mm[3][3],

			mm[2][0] * a_rRHS.mm[0][0] + mm[2][1] * a_rRHS.mm[1][0] + mm[2][2] * a_rRHS.mm[2][0] + mm[2][3] * a_rRHS.mm[3][0],
			mm[2][0] * a_rRHS.mm[0][1] + mm[2][1] * a_rRHS.mm[1][1] + mm[2][2] * a_rRHS.mm[2][1] + mm[2][3] * a_rRHS.mm[3][1],
			mm[2][0] * a_rRHS.mm[0][2] + mm[2][1] * a_rRHS.mm[1][2] + mm[2][2] * a_rRHS.mm[2][2] + mm[2][3] * a_rRHS.mm[3][2],
			mm[2][0] * a_rRHS.mm[0][3] + mm[2][1] * a_rRHS.mm[1][3] + mm[2][2] * a_rRHS.mm[2][3] + mm[2][3] * a_rRHS.mm[3][3],

			mm[3][0] * a_rRHS.mm[0][0] + mm[3][1] * a_rRHS.mm[1][0] + mm[3][2] * a_rRHS.mm[2][0] + mm[3][3] * a_rRHS.mm[3][0],
			mm[3][0] * a_rRHS.mm[0][1] + mm[3][1] * a_rRHS.mm[1][1] + mm[3][2] * a_rRHS.mm[2][1] + mm[3][3] * a_rRHS.mm[3][1],
			mm[3][0] * a_rRHS.mm[0][2] + mm[3][1] * a_rRHS.mm[1][2] + mm[3][2] * a_rRHS.mm[2][2] + mm[3][3] * a_rRHS.mm[3][2],
			mm[3][0] * a_rRHS.mm[0][3] + mm[3][1] * a_rRHS.mm[1][3] + mm[3][2] * a_rRHS.mm[2][3] + mm[3][3] * a_rRHS.mm[3][3]);
	}

	tbyte::Vector4 operator * (const tbyte::Vector4& v) const
	{
		return tbyte::Vector4(mm[0][0] * v.m_fX + mm[0][1] * v.m_fY + mm[0][2] * v.m_fZ + mm[0][3] * v.m_fW,
					mm[1][0] * v.m_fX + mm[1][1] * v.m_fY + mm[1][2] * v.m_fZ + mm[1][3] * v.m_fW,
					mm[2][0] * v.m_fX + mm[2][1] * v.m_fY + mm[2][2] * v.m_fZ + mm[2][3] * v.m_fW,
					mm[3][0] * v.m_fX + mm[3][1] * v.m_fY + mm[3][2] * v.m_fZ + mm[3][3] * v.m_fW);
	}

	operator float* ()
	{
		return &_11;
	}

	operator const float* ()
	{
		return &_11;
	}
};




GLuint LoadTexture(const char* a_szTexture, unsigned int a_uiFormat , unsigned int* a_uiWidth , unsigned int* a_uiHeight, unsigned int* a_uiBPP  );

#endif