#pragma once
#include "stdafx.h"
#include "klassen\Linie.h"
#include "GKSDrawable.h"

class CGKSLine : public CGKSDrawable {

public:
	CGKSLine::CGKSLine(int id,CLinie line = CLinie(CPunkt(),CPunkt()));
	CGKSLine::~CGKSLine();
//	virtual void Zeichnen();
	CLinie getLine();
	Drawable& const move(float x, float y, CPunkt base);
	Drawable& const rotate(float angle, CPunkt base);
	Drawable& const scale(float xFactor, float yFactor, CPunkt base);

protected:
	Gpoint AP;
	Gpoint EP;
	CLinie line;

private : 
	void draw();
	void updateGpoints();

};