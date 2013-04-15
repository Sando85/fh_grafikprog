#include "Vector.h"

#define constj 1


CVector::CVector(int i,float def[]) : CMatrix(i,constj,def,2)
{
}

CVector::CVector(int i) : CMatrix(i,constj,0)
{
}

CVector::CVector(CPunkt A, CPunkt B) : CMatrix(3,constj){
}

CVector::~CVector(){

}

void CVector::setElement(int i, int value){
	this->CMatrix::setElement(i,0,value);
}

CVector operator*(CMatrix A,CVector x){
	float val[] = {x.getValueAt(0,0),x.getValueAt(1,0),1};
	CMatrix B = CMatrix(x.getRowCount(),1,val,3);
	B = A*B;
	float vectorVal[] = {B.getValueAt(0,0),
						 B.getValueAt(1,0),
						 B.getValueAt(2,0)};
	CVector res = CVector(B.getRowCount(),vectorVal);
	return res;
}

CVector operator+(CMatrix A, CVector B){
	if(A.getColumnCount()!=B.getColumnCount() ||
		A.getRowCount() != B.getRowCount()){
			return 0;
	}

	CVector res = CVector(A.getRowCount());
	for(int i = 0; i<A.getRowCount();i++){
		for(int j = 0; j<A.getColumnCount();j++){
			res.setElement(i,A.getValueAt(i,j)+B.getValueAt(i,j));
		}
	}
	return res;
}

CVector operator-(CMatrix A, CVector B){
	if(A.getColumnCount()!=B.getColumnCount() ||
		A.getRowCount() != B.getRowCount()){
			return 0;
	}

	CVector res = CVector(A.getRowCount());
	for(int i = 0; i<A.getRowCount();i++){
		for(int j = 0; j<A.getColumnCount();j++){
			res.setElement(i,A.getValueAt(i,j)-B.getValueAt(i,j));
		}
	}
	return res;
}