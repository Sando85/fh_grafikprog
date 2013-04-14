#pragma once
#include "stdafx.h"
#include "GKSPoint.h"

CGKSPoint::CGKSPoint(int id) : CGKSDrawable(id){
	this->setPoint(new CPunkt(0.0f,0.0f));
}

CGKSPoint::CGKSPoint(int id, CPunkt* point) : CGKSDrawable(id){
	this->setPoint(point);
}

CGKSPoint::~CGKSPoint(){
	delete point;
}

CPunkt* CGKSPoint::getPoint(){

	return this->point;
}

CGKSPoint* CGKSPoint::getPointCopy(){
	return new CGKSPoint(-1,new CPunkt(this->point->get_x(),this->point->get_y()));
}

Gpoint CGKSPoint::createGpoint(CPunkt* point){
	Gpoint gPoint;
	gPoint.x = point->get_x();
	gPoint.y = point->get_y();
	return gPoint;
}

Gpoint CGKSPoint::createGpoint(float x, float y){
	Gpoint gPoint;
	gPoint.x = x;
	gPoint.y = y;
	return gPoint;
}

void CGKSPoint::setPoint(CPunkt* point){
	this->point = point;
	this->gPoint = createGpoint(point);
}

//Punkt zeichnen!
void CGKSPoint::draw(){
	
}

Drawable* CGKSPoint::move(int x, int y, CPunkt* base){
	point->move(x,y,base);
	return this;
};

Drawable* CGKSPoint::rotate(int angle, CPunkt* base){
	point->rotate(angle,base);
	return this;
};

Drawable* CGKSPoint::scale(float xFactor, float yFactor, CPunkt* base){
	point->scale(xFactor,yFactor,base);
	return this;
}


