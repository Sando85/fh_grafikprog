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