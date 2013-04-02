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

private:
	CKreis* circle;
	Gpoint gCenter;
	Gpoint peripherie;
	
	void draw();

};