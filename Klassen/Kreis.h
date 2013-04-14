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
	void move(int x,int y, CPunkt* base);
	void rotate(float angle, CPunkt* base);
	void scale(float xFactor, float yFactor, CPunkt* base);

private:
	CPunkt* m_MP;
	float m_fRadius;
};
