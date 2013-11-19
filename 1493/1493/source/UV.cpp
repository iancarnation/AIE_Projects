///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			UV.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			UV Coordinate Class Definition
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "UV.h"

//default constructor
UV::UV()
{
	m_fXmin = 0;
	m_fYmin = 0;
	m_fXmax = 0;
	m_fYmax = 0;
}

// constructor with values
UV::UV(float a_fXmin, float a_fYmin, float a_fXmax, float a_fYmax)
{
	m_fXmin = a_fXmin;
	m_fYmin = a_fYmin;
	m_fXmax = a_fXmax;
	m_fYmax = a_fYmax;
}

// destructor
UV::~UV()
{

}