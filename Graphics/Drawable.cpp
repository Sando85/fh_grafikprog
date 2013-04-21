#pragma once
#include "Drawable.h"
#include <iostream>

Drawable::Drawable(int id){
	visible = false;
	this->setID(id);
}

Drawable::~Drawable(void)
{

}

int Drawable::getID() const{
	return objID;
}

void Drawable::setID(int id){
	this->objID = id;
}

void Drawable::deleteGraphic(){
	if(this->isVisible())
		gs.gdel_seg(objID);
	visible = false;
}

bool Drawable::isVisible(){
	return visible;
}






