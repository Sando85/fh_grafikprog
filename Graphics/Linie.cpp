#pragma once
#include "Linie.h"
#include <math.h>

CLinie::CLinie(CPunkt AP,CPunkt EP){
this->m_AP = CPunkt(AP);
this->m_EP = CPunkt(EP);
}

CLinie::~CLinie(){

}

CPunkt CLinie::getAP() const{
return CPunkt(m_AP);
}

CPunkt CLinie::getEP() const{
return CPunkt(m_EP);

}

float CLinie::getLength() const{
float a = abs(m_AP.get_x()-m_EP.get_x());
float b = abs(m_AP.get_y()-m_EP.get_y());
return sqrt(pow(b,2)+pow(a,2));
}

void CLinie::Set(int id,CPunkt AP, CPunkt EP){
this->m_iObjNr = id;
this->m_AP = CPunkt(AP);
this->m_EP = CPunkt(EP);
}

const CLinie& CLinie::move(float x,float y,const CPunkt base){
//this->getAP()->set(45,90);
this->m_AP.move(x,y,base);
this->m_EP.move(x,y,base);
return *this;
}

const CLinie& CLinie::rotate(float angle,const CPunkt base){
m_AP.rotate(angle,base);
m_EP.rotate(angle,base);
return *this;
}

const CLinie& CLinie::scale(float xFactor, float yFactor,const CPunkt base){
m_AP.scale(xFactor,yFactor,base);
m_EP.scale(xFactor,yFactor,base);
return *this;
}