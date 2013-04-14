#pragma once
#include "stdafx.h"
#include "Kreis.h"
#include "GKSDrawable.h"

class CGKSCircle : public CGKSDrawable {

public: 
	CGKSCircle(int id,CKreis circle = CKreis(CPunkt(),0));
	~CGKSCircle();
//	virtual void Zeichnen();
	CKreis getCircle();
	Drawable& const move(int x, int y, CPunkt base);
	Drawable& const rotate(int angle, CPunkt base);
	Drawable& const scale(float xFactor, float yFactor, CPunkt base);

private:
	CKreis circle;
	Gpoint gCenter;
	Gpoint peripherie;
	
	void draw();

};