#pragma once
#include "GeoObject.h"

class CDatenBasis
{
public:
	CDatenBasis(void);
	~CDatenBasis(void);
	void addObject(CGeoObject*);
	void deleteObject(CGeoObject*);
	void deleteGraphic(int id);
	CGeoObject* searchObject(int);
	void redraw();

private:
	CObArray m_oaDatenBasis;
};
