#pragma once
#include "Matrix.h"
#include "Punkt.h"

class CVector : public CMatrix
{
public:
	CVector(int i, float def[]);
	CVector(int i=1);
	//IMPLEMENTIEREN!!!!
	CVector(CPunkt A, CPunkt B);
	~CVector(void);
	void setElement(int i, int value);
};

CVector operator*(CMatrix A,CVector x);
CVector operator+(CMatrix A,CVector B);
CVector operator-(CMatrix A,CVector B);