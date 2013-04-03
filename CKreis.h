#pragma once
#include "GeoObjekt.h"

class CKreis : public CGeoObjekt
{
public:
	CKreis(int,CPunkt,float);
	CKreis(int,CPunkt,CPunkt);
	~CKreis(void);
	CPunkt getMP();
	CPunkt getPP();
	void Zeichnen();
private:
	CPunkt m_mp;
	float m_radius;
};

