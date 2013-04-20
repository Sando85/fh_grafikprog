#pragma once
#include "Punkt.h"

class CLinie :
	public CGeoObject
{
public:
	CLinie(CPunkt AP = CPunkt(),CPunkt EP = CPunkt());
	~CLinie(void);
	void Set(int,CPunkt,CPunkt);
	CPunkt getAP() const;
	CPunkt getEP() const;
	const CLinie& move(float x,float y,CPunkt base);
	const CLinie& rotate(float angle,CPunkt base);
	const CLinie& scale(float xFactor, float yFactor,CPunkt base);
	float getLength() const;
	//CPunkt getCenter();

private:
	//Mit "Mutable" k�nnte man die zur�ckgegebenen Punkte der getter manipulieren
	//Das soll aber explizit �ber den setter geschehen!
	CPunkt m_AP;
	CPunkt m_EP;
};
