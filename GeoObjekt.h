#pragma once
#include "stdafx.h"

class CGeoObjekt
{
public:
	CGeoObjekt(void);
	~CGeoObjekt(void);
	void l�scheGrafik();
	virtual void Zeichnen();
protected:
	int m_iObjNr;
};

