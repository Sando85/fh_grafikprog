#pragma once
#include "Punkt.h"

class CKreis : public CGeoObject
{
public:
	CKreis(const CPunkt &center, float radius);
	~CKreis(void);
	void Set(int, const CPunkt &center, float);
	const CPunkt& getCenter() const;
	const CPunkt& getPeripheralPoint() const;
	const float getRadius() const;
	void move(int x,int y,const CPunkt& base);
	void rotate(float angle,const CPunkt& base);
	void scale(float xFactor, float yFactor,const CPunkt &base);

private:
	CPunkt m_MP;
	float m_fRadius;
};
