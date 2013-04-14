#pragma once
#include "Punkt.h"

class CLinie :
	public CGeoObject
{
public:
	CLinie(const CPunkt &AP,const CPunkt &EP);
	~CLinie(void);
	void Set(int, const CPunkt&, const CPunkt&);
	CPunkt& getAP() const;
	CPunkt& getEP() const;
	void move(int x,int y,const CPunkt& base);
	void rotate(float angle,const CPunkt& base);
	void scale(float xFactor, float yFactor,const CPunkt &base);
	float getLength() const;

private:
	//Mit "Mutable" könnte man die zurückgegebenen Punkte der getter manipulieren
	//Das soll aber explizit über den setter geschehen!
	CPunkt m_AP;
	CPunkt m_EP;
};
