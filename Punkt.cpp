#include "StdAfx.h"
#include "Punkt.h"
#include "Helper\Helper\MatrixFactory.h"

CPunkt::CPunkt(float x = 0, float y = 0){
	set(x,y);
}

CPunkt::~CPunkt(){
}

void CPunkt::set(float x, float y){
	this->x=x;
	this->y=y;
}

float CPunkt::get_x() const{
	return this->x;
}

float CPunkt::get_y() const{
	return this->y;
}

void CPunkt::move(int x, int y, const CPunkt &base){
	CVector* hx = CMatrixFactory::createHomogeneousCoordinates(x-base.get_x(),y-base.get_y());
	CVector* p = CMatrixFactory::createHomogeneousCoordinates(this->get_x(),this->get_y());
	CVector* res = *hx+*p;
	this->set(res->getValueAt(0,0), res->getValueAt(1,0));
	delete hx,p,res;
};

void CPunkt::rotate(int angle, const CPunkt &base){
	CMatrix* R = CMatrixFactory::createRotatingMatrix(angle);
	CVector* hx = CMatrixFactory::createHomogeneousCoordinates(base.get_x(),base.get_y());
	CVector* p = CMatrixFactory::createHomogeneousCoordinates(this->get_x(),this->get_y());
	CVector* res = *R**(*hx+*p);
	this->set(res->getValueAt(0,0), res->getValueAt(1,0));
	delete R,hx,p,res;
};

void CPunkt::scale(float xFactor, float yFactor,const CPunkt &base){
	CMatrix* S = CMatrixFactory::createScalingMatrix(xFactor,yFactor);
	CVector* hx = CMatrixFactory::createHomogeneousCoordinates(base.get_x(),base.get_y());
	CVector* p = CMatrixFactory::createHomogeneousCoordinates(this->get_x(),this->get_y());
	CVector* res = *S**(*hx+*p);
	this->set(res->getValueAt(0,0), res->getValueAt(1,0));
	delete S,hx,p,res;
}