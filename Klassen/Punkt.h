#pragma once
#include "GeoObject.h"

class CPunkt : public CGeoObject
{
public:
	CPunkt(float x = 0, float y = 0);
	~CPunkt(void);
	void set(float, float);
	float get_x() const;
	float get_y() const;
	const CPunkt& move(float x,float y,CPunkt base = CPunkt());
	const CPunkt& rotate(float angle,CPunkt base);
	const CPunkt& scale(float xFactor, float yFactor,CPunkt base);
	//void Zeichnen();
	
private:
	float x;
	float y;
};


	