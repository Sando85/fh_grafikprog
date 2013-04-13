#pragma once
#include "Punkt.h"

class CKreis : public CGeoObject
{
public:
	CKreis(CPunkt* Center, float radius);
	~CKreis(void);
	void Set(int, CPunkt*, float);
	CPunkt* getCenter();
	CPunkt* getPeripheralPoint();

private:
	CPunkt* m_MP;
	float m_fRadius;
};
