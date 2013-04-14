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
	void move(int x,int y,CPunkt base);
	void rotate(float angle,CPunkt base);
	void scale(float xFactor, float yFactor,CPunkt base);
	float getLength() const;

private:
	//Mit "Mutable" k�nnte man die zur�ckgegebenen Punkte der getter manipulieren
	//Das soll aber explizit �ber den setter geschehen!
	CPunkt m_AP;
	CPunkt m_EP;
};
