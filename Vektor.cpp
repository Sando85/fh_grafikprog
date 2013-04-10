#include "stdafx.h"


CVektor::CVektor(void)
{
}

CVektor::CVektor(float a, float b)
{
	m_a = a;
	m_b = b;
}

CVektor::~CVektor(void)
{
}

void CVektor::set(float a, float b)
{
	m_a = a;
	m_b = b;
}

float CVektor::get_a()
{
	return m_a;
}

float CVektor::get_b()
{
	return m_b;
}