#pragma once
#include "stdafx.h"
#include "Drawable.h"


class CDatabase {

public:
	CDatabase(void);
	~CDatabase(void);
	void addObject(Drawable &drawable);
	void deleteObject(Drawable& drawable);
	void deleteAllObjects();
	void deleteGraphic(Drawable &drawable);
	void deleteGraphic(int id);
	Drawable* const searchObject(int id) const;
	void redraw();
	void deleteAllGraphics();
	void printAllElements();

private:
	int findPosition(Drawable& drawable);
	std::vector<Drawable*> drawables;
};
