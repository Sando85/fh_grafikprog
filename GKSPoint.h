#include "stdafx.h"
#include "Punkt.h"
#include "GKSDrawable.h"

class CGKSPoint : public CGKSDrawable {

public : 
	CGKSPoint::CGKSPoint(int id);
	CGKSPoint(int id, CPunkt* point);
	~CGKSPoint();
	CPunkt* getPoint();
	void setPoint(CPunkt* point);

	static Gpoint createGpoint(CPunkt* point);
	static Gpoint createGpoint(float x, float y);
	Drawable* createDrawableObject(CGeoObject* geoObj);
	CGKSPoint* getPointCopy();
	Drawable* move(int x, int y, CPunkt* base);
	Drawable* rotate(int angle, CPunkt* base);
	Drawable* scale(float xFactor, float yFactor, CPunkt* base);

protected:
	Gpoint gPoint;
	CPunkt* point;

private :
	void draw();
};
