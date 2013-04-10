#include "StdAfx.h"


int m_iObjNr;

CGeoObject::CGeoObject(void)
{
}


CGeoObject::~CGeoObject(void)
{
}


void CGeoObject::löscheGrafik()
{
	extern CServer gs;
	gs.gdel_seg(m_iObjNr);
}

void CGeoObject::Zeichnen()
{
}

int CGeoObject::getObjNr()
{
	return m_iObjNr;
}
