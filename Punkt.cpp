#include "StdAfx.h"
#include "Punkt.h"

CPunkt::CPunkt(){
	set(0.0f,0.0f);
}

CPunkt::CPunkt(float x, float y){
	set(x,y);
}

CPunkt::~CPunkt(){
}

void CPunkt::set(float x, float y){
	this->x=x;
	this->y=y;
}

float CPunkt::get_x(){
	return x;
}

float CPunkt::get_y(){
	return y;
}
