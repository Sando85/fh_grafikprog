#pragma once
#include "stdafx.h"

class CGeoObjekt
{
public:
	CGeoObjekt(void);
	~CGeoObjekt(void);
	void löscheGrafik();
	virtual void Zeichnen();
protected:
	int m_iObjNr;
};

