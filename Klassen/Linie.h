#pragma once
#include "Punkt.h"

class CLinie :
	public CGeoObject
{
public:
	CLinie(CPunkt* AP, CPunkt* EP);
	~CLinie(void);
	void Set(int, CPunkt*, CPunkt*);
	CPunkt* getAP();
	CPunkt* getEP();
	float getLength();

private:
	CPunkt* m_AP;
	CPunkt* m_EP;
};
