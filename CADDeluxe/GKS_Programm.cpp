#pragma once
#include "StdAfx.h"
#include "GKS_Programm.h"
#include "GKSPoint.h"
#include "GKSCircle.h"
#include "GKSLine.h"

CServer CGKS_Programm::server = CServer();

CGKS_Programm::CGKS_Programm(void)
{
	db = new CGKSDatabase();
	startGKS();
}

CGKS_Programm::~CGKS_Programm(void)
{
	delete db;
	stopGKS();
}

void CGKS_Programm::execute()
{	
	CGKSLine* p_linie;
	CGKSCircle* p_kreis;
	float s45=0.5*sqrt(2.0f);
	// Figur 1
	CGKSPoint mp(-1), p1(-1), p2(-1);
	
	mp.setPoint(CPunkt(100,100));// getPoint()->set(100,100);
	
	p1.setPoint(CPunkt(100+50*s45,100+50*s45)); //getPoint()->set(100+50*s45,100+50*s45);
	p2.setPoint(CPunkt(100-50*s45,100-50*s45)); //getPoint()->set(100-50*s45,100-50*s45);
	p_linie = new CGKSLine(101,CLinie(p1.getPoint(), p2.getPoint()));
	p_linie->Zeichnen();
	db->addObject(*p_linie);

	p1.setPoint(CPunkt(100+50*s45,100-50*s45)); //getPoint()->set(100+50*s45,100-50*s45);
	p2.setPoint(CPunkt(100-50*s45,100+50*s45)); //getPoint()->set(100-50*s45,100+50*s45);

	p_linie = new CGKSLine(102,CLinie(p1.getPoint(), p2.getPoint()));
	p_linie->Zeichnen();
	db->addObject(*p_linie);

	p_kreis = new CGKSCircle(103, CKreis(mp.getPoint(),50.0f));
	p_kreis->Zeichnen();
	db->addObject(*p_kreis);
	
	// Figur 2

	//Man braucht an dieser Stelle eine Kopie des Punktes, da sonst 
	//die anderen Kreise, in denen der Punkt verwendet wird beeinflusst
	//werden
	//mp = *(mp.getPointCopy());
	mp.setPoint(CPunkt(300,100));//getPoint()->set(300,100);
	p_kreis = new CGKSCircle(201, CKreis(mp.getPoint(),25));
	p_kreis->Zeichnen();
	db->addObject(*p_kreis);
	p_kreis = new CGKSCircle(202, CKreis(mp.getPoint(),50));
	p_kreis->Zeichnen();
	db->addObject(*p_kreis);

	// Figur 3 (von unten nach oben)
	float x1=150, x2=250, y=200;
	for (int i=301; i<=304; i++)
		{
			p1.setPoint(CPunkt(x1,y)); //getPoint()->set(x1,y);
			p2.setPoint(CPunkt(x2,y)); //getPoint()->set(x2,y);
			p_linie = new CGKSLine(i, CLinie(p1.getPoint(),p2.getPoint()));
			p_linie->Zeichnen();
			db->addObject(*p_linie);
			y = y + 25;
		} 

	AfxMessageBox("Verschiebe Figur 1 um (200,130)");	
	
	
	CPunkt base; //= CPunkt(100,100);
	db->searchObject(101)->move(200,130,base);
	db->searchObject(102)->move(200,130,base);
	db->searchObject(103)->move(200,130,base);
	db->redraw();
	
	AfxMessageBox("Drehen von Figur 3 um -45� bzgl. P(150,200)");	

	for (int i=301; i<=304; i++) {
		db->searchObject(i)->rotate(-45,CPunkt(150,200));	
	}
	db->redraw();

	AfxMessageBox("Drehen von Figur 1 um 45� bzgl. des eigenen Mittelpunktes");

	base = base.move(300,230);
	db->searchObject(101)->rotate(45,base);
	db->searchObject(102)->rotate(45,base);
	db->searchObject(103)->rotate(45,base);
	db->redraw();

	AfxMessageBox("Verschieben von Figur 2 um (-150, 100)");	
	base = CPunkt(0,0);
	db->searchObject(201)->move(-150,100,base);
	db->searchObject(202)->move(-150,100,base);

	db->redraw();

	AfxMessageBox("L�sche Figur 3");	
	for (int i=301; i<=304; i++) {
		db->deleteObject(*db->searchObject(i));
	}
	db->redraw();
	//


	// Haltepunkt
	AfxMessageBox("Programm Ende !");	

}

void CGKS_Programm::startGKS(void)
{
	CServer& gs = CGKS_Programm::getCServer();
	// Server starten	
	gs.gopen_gks("con");
	gs.gopen_ws(1,NULL,GKS_SUBWINDOW);
	gs.gactivate_ws(1);
	gs.gx_set_win(1,0,400,0,300);
	gs.gx_set_vp(1,0,1,0.1,0.85);
}

void CGKS_Programm::stopGKS(void)
{
	CServer& gs = CGKS_Programm::getCServer();
	gs.gdeactivate_ws(1);
	gs.gclose_ws(1);
	// Server beenden
	gs.gclose_gks();
}

void CGKS_Programm::deleteObject(int id){
	db->deleteObject(*(db->searchObject(id)));
}

void CGKS_Programm::move(int objId,int dx, int dy, CPunkt base){
	Drawable* obj = db->searchObject(objId);
	obj->move(dx,dy,base);
}

void CGKS_Programm::rotate(int objId, int angle, CPunkt base){
	Drawable* obj = db->searchObject(objId);
	obj->rotate(angle,base);
}

void CGKS_Programm::scale(int objId, float xFactor, float yFactor, CPunkt base){
	Drawable* obj = db->searchObject(objId);
	obj->scale(xFactor,yFactor,base);
}

CServer& CGKS_Programm::getCServer(){
	return CGKS_Programm::server;
}