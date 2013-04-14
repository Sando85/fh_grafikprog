#pragma once
#include "StdAfx.h"
#include "Kreis.h"

CKreis::CKreis(const CPunkt &center, float radius){
	this->m_fRadius = radius;
	this->m_MP = center;
};

CKreis::~CKreis(){
}

void CKreis::Set(int id,const CPunkt &punkt, float radius){
	this->m_iObjNr = id;
	this->m_fRadius = radius;
	this->m_MP = punkt;
}

const CPunkt& CKreis::getPeripheralPoint() const{
	//Ruft den Kosntruktor mit defaultwerten auf...zumindest sollte er das
	CPunkt point;
	point.set(getCenter().get_x()+m_fRadius,getCenter().get_y());
	return CPunkt(point);

}

const CPunkt& CKreis::getCenter() const{
	return CPunkt(this->m_MP);	
};

const float CKreis::getRadius() const {
	return m_fRadius;
}

void CKreis::move(int x,int y,const CPunkt &base){
	m_MP.move(x,y,base);
}

void CKreis::rotate(float angle,const CPunkt &base){
	m_MP.rotate(angle,base);
}

void CKreis::scale(float xFactor, float yFactor,const CPunkt &base){
	m_MP.scale(xFactor,yFactor,base);
}