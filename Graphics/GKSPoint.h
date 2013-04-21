#pragma once
#include "Punkt.h"
#include "GKSDrawable.h"

class CGKSPoint : public CGKSDrawable {

public : 
	CGKSPoint(int id,CPunkt point = CPunkt(0,0));
	~CGKSPoint();
	CPunkt getPoint() const;
	void setPoint(CPunkt point);

	static Gpoint createGpoint(CPunkt point);
	static Gpoint createGpoint(float x, float y);
	//Drawable* createDrawableObject(CGeoObject* geoObj);
	Drawable& const move(float x, float y,CPunkt base);
	Drawable& const rotate(float angle,CPunkt base);
	Drawable& const scale(float xFactor, float yFactor,CPunkt base);


protected:
	Gpoint gPoint;
	CPunkt point;

private :
	void draw();
	virtual void updateGpoints();
};