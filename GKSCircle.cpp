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

