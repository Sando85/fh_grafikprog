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