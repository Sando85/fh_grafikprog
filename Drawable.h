#pragma once
#include "stdafx.h"
#include "GKS_Programm.h"

class Drawable
{

public:
	
	~Drawable();
	virtual void Zeichnen() = 0;
	int getID();
	void deleteGraphic();
	bool isVisible();

protected:
	void setID(int id);
	int objID;

	Drawable(int id);
	virtual void draw() = 0;
	bool visible;

};

