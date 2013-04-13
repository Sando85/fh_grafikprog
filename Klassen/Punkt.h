#pragma once
#include "GeoObject.h"

class CPunkt : public CGeoObject
{
public:
	CPunkt();
	CPunkt(float x, float y);
	~CPunkt(void);
	void set(float, float);
	float get_x();
	float get_y();
	//void Zeichnen();
	
private:
	float x, y;
};


	