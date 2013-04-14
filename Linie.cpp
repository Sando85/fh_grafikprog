#pragma once
#include "StdAfx.h"
#include "Linie.h"

CLinie::CLinie(CPunkt* AP,CPunkt* EP){
	this->m_AP = AP;
	this->m_EP = EP;
}

CLinie::~CLinie(){
	delete m_AP;
	delete m_EP;
}

CPunkt* CLinie::getAP(){
	return this->m_AP;
}

CPunkt* CLinie::getEP(){
	return this->m_EP;
	
}

float CLinie::getLength(){
	float a = abs(m_AP->get_x()-m_EP->get_x());
	float b = abs(m_AP->get_y()-m_EP->get_y());
	return sqrt(pow(b,2)+pow(a,2));
}

void CLinie::Set(int id, CPunkt* AP, CPunkt* EP){
	this->m_iObjNr = id;
	this->m_AP = AP;
	this->m_EP = EP;
}

void CLinie::move(int x,int y, CPunkt* base){
	//this->getAP()->set(45,90);
	this->getAP()->move(x,y,base);
	this->getEP()->move(x,y,base);
}

void CLinie::rotate(float angle, CPunkt* base){
	m_AP->rotate(angle,base);
	m_EP->rotate(angle,base);
}

void CLinie::scale(float xFactor, float yFactor,CPunkt* base){
	m_AP->scale(xFactor,yFactor,base);
	m_EP->scale(xFactor,yFactor,base);
}