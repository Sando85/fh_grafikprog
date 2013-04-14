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
	void move(int x,int y, CPunkt* base);
	void rotate(int angle, CPunkt* base);
	void scale(float xFactor, float yFactor, CPunkt* base);
	//void Zeichnen();
	
private:
	float x, y;
};


	