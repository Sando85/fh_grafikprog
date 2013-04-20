#pragma once
#include "StdAfx.h"
#include "klassen\Kreis.h"

CKreis::CKreis(CPunkt center, float radius){
	this->m_fRadius = radius;
	this->m_MP = center;
};

CKreis::~CKreis(){
}

void CKreis::Set(int id, CPunkt punkt, float radius){
	this->m_iObjNr = id;
	this->m_fRadius = radius;
	this->m_MP = punkt;
}

CPunkt CKreis::getPeripheralPoint() const{
	//Ruft den Kosntruktor mit defaultwerten auf...zumindest sollte er das
	CPunkt point;
	point.set(getCenter().get_x()+m_fRadius,getCenter().get_y());
	return CPunkt(point);

}

CPunkt CKreis::getCenter() const{
	return CPunkt(m_MP);	
};

float CKreis::getRadius() const {
	return m_fRadius;
}

const CKreis& CKreis::move(float x,float y,const CPunkt base){
	m_MP.move(x,y,base);
	return *this;
}

const CKreis& CKreis::rotate(float angle,const CPunkt base){
	m_MP.rotate(angle,base);
	return *this;
}

const CKreis& CKreis::scale(float xFactor, float yFactor,const CPunkt base){
	m_MP.scale(xFactor,yFactor,base);
	return *this;
}