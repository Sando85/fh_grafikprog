#include "stdafx.h"
#include "GKSLine.h"
#include "GKSPoint.h"
#include "Drawable.h"

CGKSLine::CGKSLine(int id,CLinie* line) : CGKSDrawable(id){
	this->line = line;
	this->AP = CGKSPoint::createGpoint(line->getAP());
	this->EP = CGKSPoint::createGpoint(line->getEP());
}

CGKSLine::~CGKSLine(){
	delete line;
};

CLinie* CGKSLine::getLine(){
	return line;
}

void CGKSLine::draw(){
	Gpoint points[] = {AP,EP,AP};
	Gpoint_list list = {3,points};
	gs.gpolyline(&list);
};

