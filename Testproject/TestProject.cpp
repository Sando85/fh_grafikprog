// TestProject.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "Matrix.h"
#include "MatrixFactory.h"
#include "Punkt.h"
#include "Drawable.h"
#include <iostream>

using namespace std;

void printMatrix(CMatrix A);

int imax = 2;
int jmax = 3;

int _tmain(int argc, _TCHAR* argv[])
{

	CMatrix A = CMatrix(imax,jmax,4);
	CMatrix B = CMatrix(jmax,imax,4);
	CMatrix C(0,0);
	CMatrix D(0,0,0);
	
	float a[] = {1,2,3,4,5,6};
	float b[] = {6,-1,3,2,0,-3};
	cout<<"Matrix erstellt mit i = "<<A.getRowCount()<<" und j = "<<A.getColumnCount()<<endl;
	cout<<"Das sieht wie folgt aus: \n"<<endl;
	printMatrix(A);
	cout<<"\n"<<endl;
	A.setElement(0,0,9);
	A.setElement(0,1,8);
	A.setElement(0,2,7);
	A.setElement(1,0,6);
	A.setElement(1,1,5);
	A.setElement(1,2,4);
	printMatrix(A);
	cout<<"\n"<<endl;
	A.setMatrix(a,sizeof(a)/sizeof(float));
	printMatrix(A);
	cout<<"\n"<<endl;
	B.setMatrix(b,sizeof(a)/sizeof(float));
	printMatrix(A);
	cout<<"\n*\n"<<endl;
	printMatrix(B);
	cout<<"------------------------"<<endl;
	//C = ((*A)*(*B));
	C = (A * B);
	printMatrix(C);
	cout<<"Matrizen lassen sich nicht multiplizieren!\n"<<endl;

	system("Pause");
	CPunkt p(3,0);
	float coord[] = {p.get_x(),p.get_y()};
	CVector res(3);

	CVector x = CMatrixFactory::createHomogeneousCoordinates(p.get_x(),p.get_y()); 
	CMatrix T = CMatrixFactory::createMovingMatrix(2,3);
	CMatrix R = CMatrixFactory::createRotatingMatrix(360);
	CMatrix S = CMatrixFactory::createScalingMatrix(2,4);
	

	cout<<"\n\nVerschiedene Matrizen:"<<endl;
	cout<<"Homogene Koordinaten: "<<endl;
	printMatrix(x);
	cout<<"\n"<<endl;
	cout<<"Verschiebe Matrix: "<<endl;
	printMatrix(T);
	cout<<"\n"<<endl;
	cout<<"Rotations Matrix: "<<endl;
	printMatrix(R);
	cout<<"\n"<<endl;
	cout<<"Skalierungs Matrix: "<<endl;
	printMatrix(S);
	cout<<"\n"<<endl;
	cout<<"Addition (1,2,3) + (9,8,7)\n"<<endl;
	float val[] = {1,2,3};
	float val2[] = {9,8,7};
	CMatrix T1 = CMatrixFactory::createMovingMatrix(15,10);
	CVector v1 = CVector(3,val);
	CVector v2 = CVector(3,val2);
	CVector v3 = (v1+v2);
	printMatrix(v3);

	cout<<"\n\n"<<endl;

	system("Pause");

	cout<<"Und nun ein bisschen rechnen: \n"<<endl;
	cout<<"(3,0) verschieben um (2,3): "<<endl;
	res = T*x;
	printMatrix(res);
	cout<<"\n"<<endl;
	cout<<"Skalieren um Faktor (2,4):"<<endl;
	res = S*res;
	printMatrix(res);
	cout<<"\n"<<endl;
	cout<<"Rotieren: "<<endl;
	res = R * res;
	printMatrix(res);

	system("Pause");

	return 0;
}


void printMatrix(CMatrix A){
	float val = 0;
	for(int i = 0; i<A.getRowCount();i++){
		for(int j = 0; j<A.getColumnCount() ; j++){
			val = A.getValueAt(i,j);
			cout<<(val)<<"\t";
		}
		cout<<"\n"<<endl;
	}
}


