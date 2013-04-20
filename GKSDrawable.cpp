#pragma once
#include "StdAfx.h"
#include "GKSDrawable.h"
#include <iostream>

CGKSDrawable::~CGKSDrawable(){};

void CGKSDrawable::Zeichnen(){
	
	createSegment(objID);
	draw();
	closeSegment();
	visible = true;
}

void CGKSDrawable::createSegment(int id){
	gs.gcreate_seg(id);
}

void CGKSDrawable::closeSegment(){
	gs.gclose_seg();
}