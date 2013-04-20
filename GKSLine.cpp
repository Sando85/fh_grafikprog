#include "stdafx.h"
#include "GKSLine.h"
#include "GKSPoint.h"
#include "Drawable.h"

CGKSLine::CGKSLine(int id,CLinie line) : CGKSDrawable(id){
	this->line = line;
	this->AP = CGKSPoint::createGpoint(line.getAP());
	this->EP = CGKSPoint::createGpoint(line.getEP());
}

CGKSLine::~CGKSLine(){
};

CLinie CGKSLine::getLine(){
	return CLinie(line);
}

void CGKSLine::draw(){
	Gpoint points[] = {AP,EP,AP};
	Gpoint_list list = {3,points};
	gs.gpolyline(&list);
};

Drawable& const CGKSLine::move(float x, float y, CPunkt base){
	//this->getLine()->getAP()->set(50,600);
	this->line.move(x,y,base);
	updateGpoints();
	return *this;
};

Drawable& const CGKSLine::rotate(float angle, CPunkt base){
	this->line.rotate(angle,base);
	updateGpoints();
	return *this;
};

Drawable& const CGKSLine::scale(float xFactor,float yFactor,CPunkt base){
	this->line.scale(xFactor,yFactor,base);
	updateGpoints();
	return *this;
}

void CGKSLine::updateGpoints(){
	AP = CGKSPoint::createGpoint(line.getAP());
	EP = CGKSPoint::createGpoint(line.getEP());
};

