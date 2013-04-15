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
	const CKreis& move(float x,float y,CPunkt base);
	const CKreis& rotate(float angle,CPunkt base);
	const CKreis& scale(float xFactor, float yFactor,CPunkt base);

private:
	CPunkt m_MP;
	float m_fRadius;
};
