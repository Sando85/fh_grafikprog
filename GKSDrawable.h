#pragma once
#include "stdafx.h"
#include "Drawable.h"
#include "GKS_Programm.h"

class CGKSDrawable : public Drawable
{

public:
	
	~CGKSDrawable();
	void Zeichnen();

protected:

	CGKSDrawable(int id) : Drawable(id){};
	virtual void draw() = 0;

private:
	void createSegment(int id);
	void closeSegment();

};
