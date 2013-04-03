#include "StdAfx.h"

CPunkt::CPunkt(void)
{
}


CPunkt::~CPunkt(void)
{
}

void CPunkt::set(float x, float y)
{
	m_x = x;
	m_y = y;
}

float CPunkt::getX()
{
	return m_x;
}

float CPunkt::getY()
{
	return m_y;
}
