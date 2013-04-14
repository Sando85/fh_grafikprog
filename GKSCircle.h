#pragma once
#include "stdafx.h"
#include "Kreis.h"
#include "GKSDrawable.h"

class CGKSCircle : public CGKSDrawable {

public: 
	CGKSCircle(int id);
	CGKSCircle(int id, CKreis* circle);
	~CGKSCircle();
//	virtual void Zeichnen();
	CKreis* getCircle();
	Drawable* move(int x, int y, CPunkt* base);
	Drawable* rotate(int angle, CPunkt* base);
	Drawable* scale(float xFactor, float yFactor, CPunkt* base);

private:
	CKreis* circle;
	Gpoint gCenter;
	Gpoint peripherie;
	
	void draw();

};