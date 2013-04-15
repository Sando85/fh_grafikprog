#pragma once
#include "stdafx.h"
#include "GKSPoint.h"

CGKSPoint::CGKSPoint(int id,CPunkt point) : CGKSDrawable(id){
	this->setPoint(point);
}

CGKSPoint::~CGKSPoint(){
}

CPunkt CGKSPoint::getPoint() const{
	return CPunkt(point);
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

Drawable& const CGKSPoint::move(float x, float y,CPunkt base){
	point.move(x,y,base);
	updateGpoints();
	return *this;
};

Drawable& const CGKSPoint::rotate(float angle, CPunkt base){
	point.rotate(angle,base);
	updateGpoints();
	return *this;
};

Drawable& const CGKSPoint::scale(float xFactor, float yFactor, CPunkt base){
	point.scale(xFactor,yFactor,base);
	updateGpoints();
	return *this;
}

void CGKSPoint::updateGpoints(){
	gPoint = CGKSPoint::createGpoint(point);
}


