#pragma once
#include "../stdafx.h"
#include <GServer.h>

class CGeoObject// : public CObject
{

public:
	CGeoObject(void);
	~CGeoObject(void);
	int getObjNr() const;
	void LoescheGrafik();
	//virtual void getDefaultBasePoint = 0;
protected:
	int m_iObjNr;

};
