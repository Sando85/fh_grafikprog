#pragma once
#include "stdafx.h"
#include "Drawable.h"
#include "GServer.h"



class CGKSDrawable : public Drawable
{

public:
	
	~CGKSDrawable();
	void Zeichnen();
	void setCServer(CServer& cServer);

protected:

	static CServer* gs;
	CGKSDrawable(int id) : Drawable(id){};
	virtual void draw() = 0;

private:

	void createSegment(int id);
	void closeSegment();
	virtual void updateGpoints() = 0;

};
