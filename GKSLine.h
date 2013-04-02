#pragma once
#include "stdafx.h"
#include "Linie.h"
#include "GKSDrawable.h"

class CGKSLine : public CGKSDrawable {

public:
	CGKSLine::CGKSLine(int id, CLinie* line);
	CGKSLine::~CGKSLine();
//	virtual void Zeichnen();
	CLinie* getLine();

protected:
	Gpoint AP;
	Gpoint EP;
	CLinie* line;

private : 
	void draw();

};