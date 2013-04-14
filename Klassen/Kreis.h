#pragma once
#include "Punkt.h"

class CKreis : public CGeoObject
{
public:
	CKreis(CPunkt center = CPunkt(), float radius = 0);
	~CKreis(void);
	void Set(int, CPunkt center, float);
	CPunkt getCenter() const;
	CPunkt getPeripheralPoint() const;
	float getRadius() const;
	void move(int x,int y,CPunkt base);
	void rotate(float angle,CPunkt base);
	void scale(float xFactor, float yFactor,CPunkt base);

private:
	CPunkt m_MP;
	float m_fRadius;
};
