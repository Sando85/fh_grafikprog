#pragma once
#include "stdafx.h"

class CKreis : public CGeoObject
{

public:
	CKreis(int,CPunkt,float);
	CKreis(int,CPunkt,CPunkt);
	~CKreis(void);
	CPunkt getMP();
	CPunkt getPP();
	void Zeichnen();
	void schieben(CVektor*);
	void drehen(CPunkt*,float);

private:
	CPunkt m_mp;
	float m_radius;
};

