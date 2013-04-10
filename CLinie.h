#pragma once
#include "GeoObject.h"

class CLinie : public CGeoObject
{
public:

	CLinie(int ,CPunkt,CPunkt);
	~CLinie(void);
	CPunkt getAP();
	CPunkt getEP();
	void Zeichnen();
	void schieben(CVektor*);
	void drehen(CPunkt*,float);

private:
	CPunkt m_ap;
	CPunkt m_ep;
};

