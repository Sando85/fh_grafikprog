#pragma once
#include "StdAfx.h"
#include <GServer.h>

class CGeoObject : public CObject
{

public:
	CGeoObject(void);
	~CGeoObject(void);
	int getObjNr();
	void LoescheGrafik();
	virtual void move(int x,int y) = 0;
	virtual void rotate(float angle) = 0;

protected:
	int m_iObjNr;

};
