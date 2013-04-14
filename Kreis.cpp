#pragma once
#include "StdAfx.h"
#include "Kreis.h"

CKreis::CKreis(CPunkt* middle, float radius){
	this->m_fRadius = radius;
	this->m_MP = middle;
};

CKreis::~CKreis(){
	delete m_MP;
}

void CKreis::Set(int id, CPunkt* punkt, float radius){
	this->m_iObjNr = id;
	this->m_fRadius = radius;
	this->m_MP = punkt;
}

CPunkt* CKreis::getPeripheralPoint(){

	CPunkt* pPoint = new CPunkt(0.0f,0.0f);
	pPoint->set(getCenter()->get_x()+m_fRadius,getCenter()->get_y());
	return pPoint;

}

CPunkt* CKreis::getCenter(){
	return m_MP;	
};

void CKreis::move(int x,int y, CPunkt* base){
	m_MP->move(x,y,base);
}

void CKreis::rotate(float angle, CPunkt* base){
	m_MP->rotate(angle,base);
}

void CKreis::scale(float xFactor, float yFactor, CPunkt* base){
	m_MP->scale(xFactor,yFactor,base);
}