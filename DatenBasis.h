#pragma once
#include "stdafx.h"

class CDatenBasis
{
public:
	CDatenBasis(void);
	~CDatenBasis(void);
	void addObject(CGeoObject*);
	void deleteObject(CGeoObject*);
	CGeoObject* searchObject(int);
	void redraw();

private:
	CObArray m_oaDatenBasis;
};
