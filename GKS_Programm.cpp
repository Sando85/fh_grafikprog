#pragma once
#include "StdAfx.h"
#include "GKS_Programm.h"
#include "GKSPoint.h"
#include "GKSCircle.h"
#include "GKSLine.h"

CGKS_Programm::CGKS_Programm(void)
{
	db = new CDatabase();
}

CGKS_Programm::~CGKS_Programm(void)
{
	delete db;
}

void CGKS_Programm::execute()
{	

	CGKSLine* p_linie;
	CGKSCircle* p_kreis;
	float s45=0.5*sqrt(2.0f);
	// Figur 1
	CGKSPoint mp(-1), p1(-1), p2(-1);
	
	mp.getPoint()->set(100,100);
	
	p1.getPoint()->set(100+50*s45,100+50*s45);
	p2.getPoint()->set(100-50*s45,100-50*s45);
	
	p_linie = new CGKSLine(101,new CLinie(p1.getPoint(), p2.getPoint()));
	p_linie->Zeichnen();
	db->addObject(p_linie);

	p1.getPoint()->set(100+50*s45,100-50*s45);
	p2.getPoint()->set(100-50*s45,100+50*s45);

	p_linie = new CGKSLine(102,new CLinie(p1.getPoint(), p2.getPoint()));
	p_linie->Zeichnen();
	db->addObject(p_linie);

	p_kreis = new CGKSCircle(103,new CKreis(mp.getPoint(),50.0f));
	p_kreis->Zeichnen();
	db->addObject(p_kreis);

	// Figur 2

	//Man braucht an dieser Stelle eine Kopie des Punktes, da sonst 
	//die anderen Kreise, in denen der Punkt verwendet wird beeinflusst
	//werden
	mp = *(mp.getPointCopy());
	mp.getPoint()->set(300,100);
	p_kreis = new CGKSCircle(201, new CKreis(mp.getPoint(),25));
	p_kreis->Zeichnen();
	db->addObject(p_kreis);
	p_kreis = new CGKSCircle(202, new CKreis(mp.getPoint(),50));
	p_kreis->Zeichnen();
	db->addObject(p_kreis);

	// Figur 3 (von unten nach oben)
	float x1=150, x2=250, y=200;
	for (int i=301; i<=304; i++)
		{
			p1.getPoint()->set(x1,y); p2.getPoint()->set(x2,y);
			p_linie = new CGKSLine(i, new CLinie(p1.getPoint(),p2.getPoint()));
			p_linie->Zeichnen();
			db->addObject(p_linie);
			y = y + 25;
		} 
		
	AfxMessageBox("L�sche Figur 1");	
	//Loesche Figur 1
	db->deleteObject(db->searchObject(101));
	db->deleteObject(db->searchObject(102));
	db->deleteObject(db->searchObject(103));

	AfxMessageBox("L�sche 2 Mittlere Linien aus Figur 3");	
	//Loesche 2 Linien aus Figur 3
	db->deleteObject(db->searchObject(302));
	db->deleteObject(db->searchObject(303));

	AfxMessageBox("L�sche alle Grafiken");	
	//Loesche alle Grafiken
	db->deleteAllGraphics();

	AfxMessageBox("Zeichne neu");	
	//Neuzeichnen
	db->redraw();

	// Haltepunkt
	AfxMessageBox("Programm Ende !");	

}

void CGKS_Programm::startGKS(void)
{
	// Server starten	
	gs.gopen_gks("con");
	gs.gopen_ws(1,NULL,GKS_SUBWINDOW);
	gs.gactivate_ws(1);
	gs.gx_set_win(1,0,400,0,300);
	gs.gx_set_vp(1,0,1,0.1,0.85);
}

void CGKS_Programm::stopGKS(void)
{
	gs.gdeactivate_ws(1);
	gs.gclose_ws(1);
	// Server beenden
	gs.gclose_gks();
}

void CGKS_Programm::deleteObject(int id){
	db->deleteObject(db->searchObject(id));
}
