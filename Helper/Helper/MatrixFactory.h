#pragma once
#include "Matrix.h"
#include "Vector.h"
#include "../../Klassen/Punkt.h"

class CMatrixFactory
{

public:
	static CMatrix CMatrixFactory::createMovingMatrix(int dx, int dy);
	static CMatrix CMatrixFactory::createScalingMatrix(int xFactor, int yFactor);
	static CMatrix CMatrixFactory::createRotatingMatrix(int angle);
	static CVector CMatrixFactory::createHomogeneousCoordinates(int x, int y);

private:
	CMatrixFactory(void);
	virtual ~CMatrixFactory(void) = 0;
};

