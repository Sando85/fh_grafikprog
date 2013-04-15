#pragma once
#include "stdafx.h"
#include "GKS_Programm.h"
#include "Klassen\Punkt.h"

class Drawable
{

public:
	
	~Drawable();
	virtual void Zeichnen() = 0;
	int getID() const;
	void deleteGraphic();
	bool isVisible();
	virtual Drawable& const move(int x, int y,CPunkt base) = 0;
	virtual Drawable& const rotate(int angle,const CPunkt base) = 0;
	virtual Drawable& const scale(float xFactor,float yFactor, const CPunkt base) = 0;


protected:
	void setID(int id);
	int objID;

	Drawable(int id);
	virtual void draw() = 0;
	bool visible;

};

