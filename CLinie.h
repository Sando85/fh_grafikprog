#pragma once
#include "GeoObjekt.h"

class CLinie : public CGeoObjekt
{
public:
	CLinie(int ,CPunkt,CPunkt);
	~CLinie(void);
	CPunkt getAP();
	CPunkt getEP();
	void Zeichnen();
private:
	CPunkt m_ap;
	CPunkt m_ep;
};

