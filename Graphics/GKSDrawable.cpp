#pragma once
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
	if(gs){
		gs->gcreate_seg(id);
	}
}

void CGKSDrawable::closeSegment(){
	if(gs){
		gs->gclose_seg();
	}
}

void CGKSDrawable::setCServer(CServer& cServer){
	gs = &cServer;
}