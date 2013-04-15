#include "MatrixFactory.h"
#define _USE_MATH_DEFINES
#include <math.h>
#define elements 9

//Private to prevent instanciation
CMatrixFactory::CMatrixFactory(void)
{
}

//Not needed
CMatrixFactory::~CMatrixFactory(void)
{
}

CVector CMatrixFactory::createHomogeneousCoordinates(int x, int y){
	CVector hCoordinates = CVector(3);
	hCoordinates.setElement(0,x);
	hCoordinates.setElement(1,y);
	return hCoordinates;
}

CMatrix CMatrixFactory::createMovingMatrix(int dx, int dy){
	CMatrix movingMatrix = CMatrix(3,3); 
	float values[] = {1,0,dx,
				    0,1,dy,
				    0,0,1};
	movingMatrix.setMatrix(values,elements);
	return movingMatrix;
};

CMatrix CMatrixFactory::createScalingMatrix(int xFactor, int yFactor){
	CMatrix scalingMatrix = CMatrix(3,3); 
	float values[] = {xFactor, 0, 0,
					  0, yFactor, 0,
					  0, 0 ,1};
	scalingMatrix.setMatrix(values,elements);
	return scalingMatrix;
}

CMatrix CMatrixFactory::createRotatingMatrix(int angle){
	CMatrix rotatingMatrix = CMatrix(3,3); 
	float dToR = angle * (M_PI/180);
	float values[] = {cos(dToR), -sin(dToR), 0,
					  sin(dToR), cos(dToR), 0,
					  0, 0, 1};
	rotatingMatrix.setMatrix(values,elements);
	return rotatingMatrix;
};

