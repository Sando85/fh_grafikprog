#pragma once
#include "stdafx.h"
#include "GKSPoint.h"
#include "GKSCircle.h"

CGKSCircle::CGKSCircle(int id) : CGKSDrawable(id){
	this->circle = new CKreis(new CPunkt(),0);
}

CGKSCircle::CGKSCircle(int id, CKreis* circle) : CGKSDrawable(id){
	this->circle = circle;
	this->gCenter = CGKSPoint::createGpoint(circle->getCenter());
}

CGKSCircle::~CGKSCircle(){
	delete circle;
}

CKreis* CGKSCircle::getCircle(){
	return circle;
}

void CGKSCircle::draw(){
	Gpoint points[] = {gCenter,CGKSPoint::createGpoint(circle->getPeripheralPoint())};
	Gpoint_list list = {2,points};
	gs.gx_circle(&list);
}

Drawable* CGKSCircle::move(int x, int y, CPunkt* base){
	circle->move(x,y,base);
	return this;
};

Drawable* CGKSCircle::rotate(int angle, CPunkt* base){
	circle->rotate(angle,base);
	return this;
};

Drawable* CGKSCircle::scale(float xFactor, float yFactor, CPunkt* base){
	circle->scale(xFactor, yFactor,base);
	return this;
};

