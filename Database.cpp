#pragma once
#include "stdafx.h"
#include "Database.h"

/**
*	KONSTURKTOR / DESTRUKTOR
**/

CDatabase::CDatabase(){
	drawables = new std::vector<Drawable> ();
};

CDatabase::~CDatabase(){
	drawables->clear();
	delete drawables;
};

/**
*	PUBLICS
**/

void CDatabase::addObject(Drawable &drawable){
	drawables->push_back(drawable);
};

void CDatabase::deleteObject(Drawable &drawable){
	deleteGraphic(drawable);
	drawables->erase(drawables->begin()+findPosition(drawable));
};

void CDatabase::deleteGraphic(Drawable &drawable){
	drawable.deleteGraphic();
};

void CDatabase::deleteGraphic(int id){
		searchObject(id)->deleteGraphic();
};

Drawable* const CDatabase::searchObject(int id) const{
	std::vector<Drawable>::iterator it = drawables->begin();
	while(it != drawables->end()){
		Drawable* p = &(*it++);
		if(p->getID() == id)
			return p;
	};
	return 0;
};

void CDatabase::redraw(){
	deleteAllGraphics();
	std::vector<Drawable>::iterator it = drawables->begin();
	while(it != drawables->end()){
		Drawable* p = &(*it++);
		p->Zeichnen();
	};
};

void CDatabase::deleteAllGraphics(){
	std::vector<Drawable>::iterator it = drawables->begin();
	while(it != drawables->end()){
		Drawable* p = &(*it++);
		p->deleteGraphic();
	};
};

/**
*	PRIVATES
**/

int CDatabase::findPosition(Drawable& drawable){
	for(unsigned int i = 0;i<(drawables->size());i++){
		if(drawables->at(i)!=0 && drawable->getID() == drawables->at(i)->getID()){
				return i;
		};
	};
	return 0; 
};
