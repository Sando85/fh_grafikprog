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
	void move(int x,int y, CPunkt* base);
	void rotate(float angle, CPunkt* base);
	void scale(float xFactor, float yFactor, CPunkt* base);
	float getLength();

private:
	CPunkt* m_AP;
	CPunkt* m_EP;
};
