#pragma once
#include "stdafx.h"

class CVektor;
class CGeoObject : public CObject
{

public:
	CGeoObject(void);
	~CGeoObject(void);
	void löscheGrafik();
	virtual void Zeichnen() = 0;
	virtual void schieben(CVektor*) = 0;
	virtual void drehen(CPunkt*, float) = 0;
	int getObjNr();

protected:
	int m_iObjNr;
};

