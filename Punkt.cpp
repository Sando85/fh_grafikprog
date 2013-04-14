#include "StdAfx.h"
#include "Punkt.h"
#include "Helper\Helper\MatrixFactory.h"

CPunkt::CPunkt(float x , float y ){
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

void CPunkt::move(int x, int y,CPunkt base){
	CVector hx = CMatrixFactory::createHomogeneousCoordinates(x-base.get_x(),y-base.get_y());
	CVector p = CMatrixFactory::createHomogeneousCoordinates(this->get_x(),this->get_y());
	CVector res = hx+p;
	this->set(res.getValueAt(0,0), res.getValueAt(1,0));
};

void CPunkt::rotate(int angle, CPunkt base){
	CMatrix R = CMatrixFactory::createRotatingMatrix(angle);
	CVector hx = CMatrixFactory::createHomogeneousCoordinates(base.get_x(),base.get_y());
	CVector p = CMatrixFactory::createHomogeneousCoordinates(this->get_x(),this->get_y());
	CVector res = R*(hx+p);
	this->set(res.getValueAt(0,0), res.getValueAt(1,0));
};

void CPunkt::scale(float xFactor, float yFactor, CPunkt base){
	CMatrix S = CMatrixFactory::createScalingMatrix(xFactor,yFactor);
	CVector hx = CMatrixFactory::createHomogeneousCoordinates(base.get_x(),base.get_y());
	CVector p = CMatrixFactory::createHomogeneousCoordinates(this->get_x(),this->get_y());
	CVector res = S*(hx+p);
	this->set(res.getValueAt(0,0), res.getValueAt(1,0));
}