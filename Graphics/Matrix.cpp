#pragma once
#include "../CADDeluxe/StdAfx.h"
#include "Matrix.h"

//Def --> Vorbelegung
CMatrix::CMatrix(int i, int j, float def){
	float val[] = {def};
	init(i,j,val,0);
}

CMatrix::CMatrix(int i, int j, float values[], int elementCount){
	init(i,j, values, elementCount);
}


CMatrix::~CMatrix(void)
{
	//delete[] matrix;
}

void CMatrix::init(int i, int j, float def[], int elementCount){
	this->imax = i;
	this->jmax = j;
	matrix = new float[i*j];
	for(int k = 0; k<i*j; k++){
		matrix[k] = def[k>elementCount ? 0 : k];
	}
};

void CMatrix::init(int i, int j, float def){
	float val[] = {def};
	init(i,j,val,0);
}

float CMatrix::getValueAt(int i, int j) const{
	return matrix[(i * this->getColumnCount())+j];
}

void CMatrix::setElement(int i, int j, int value){
	matrix[(i * this->getColumnCount())+j] = value;
}

void CMatrix::setMatrix(float values[], int elementCount){
	int valueSize = (sizeof(values)*elementCount)/sizeof(float);

	for(int i = 0; i<valueSize || i<imax*jmax;i++){
		this->matrix[i] = values[i];
	}
}

int CMatrix::getElementCount() const{
	return imax * jmax;
}

int CMatrix::getRowCount() const{
	return this->imax;
}

int CMatrix::getColumnCount() const{
	return this->jmax;
}

CMatrix operator*(CMatrix A, CMatrix B){
	CMatrix C = CMatrix(A.getRowCount(),B.getColumnCount());
	float value = 0;
	//Bedingung für Matrizenmultiplikation i1 == j2 && j1 == i2
	if(//A.getRowCount() != B.getColumnCount() &&
		A.getColumnCount() != B.getRowCount()){
			return CMatrix(1,1,0);
	}


	for(int i = 0; i<A.getRowCount();i++){
		for(int j = 0; j<A.getColumnCount();j++){
			for(int k = 0; k<B.getRowCount();k++){
				value += (A.getValueAt(i,k)) * (B.getValueAt(k,j));
			}
			C.setElement(i,j,value);
			value = 0;
		}
	}
	return C;
}






