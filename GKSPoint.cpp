#pragma once
#include "stdafx.h"
#include "GKSPoint.h"

CGKSPoint::CGKSPoint(int id,CPunkt point) : CGKSDrawable(id){
	this->setPoint(point);
}

CGKSPoint::~CGKSPoint(){
}

CPunkt CGKSPoint::getPoint() const{
	return point;
}

Gpoint CGKSPoint::createGpoint(CPunkt point){
	Gpoint gPoint;
	gPoint.x = point.get_x();
	gPoint.y = point.get_y();
	return gPoint;
}

Gpoint CGKSPoint::createGpoint(float x, float y){
	Gpoint gPoint;
	gPoint.x = x;
	gPoint.y = y;
	return Gpoint(gPoint);
}

void CGKSPoint::setPoint(CPunkt point){
	this->point = point;
	this->gPoint = createGpoint(point);
}

//Punkt zeichnen!
void CGKSPoint::draw(){
	
}

Drawable& const CGKSPoint::move(int x, int y,CPunkt base){
	point.move(x,y,base);
	return *this;
};

Drawable& const CGKSPoint::rotate(int angle, CPunkt base){
	point.rotate(angle,base);
	return *this;
};

Drawable& const CGKSPoint::scale(float xFactor, float yFactor, CPunkt base){
	point.scale(xFactor,yFactor,base);
	return *this;
}


