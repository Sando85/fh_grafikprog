#include "StdAfx.h"
#include "GKS_Programm.h"

extern CServer gs;
extern CDatenBasis* db;

CGKS_Programm::CGKS_Programm(void)
{
}

CGKS_Programm::~CGKS_Programm(void)
{
}

void CGKS_Programm::execute()
{	

CLinie* p_linie;
CKreis* p_kreis;
float s45=0.5*sqrt(2.0f);
// Figur 1
CPunkt mp;
CPunkt p1;
CPunkt p2;
mp.set(100,100);
p_kreis = new CKreis(103,mp,50);
db->addObject(p_kreis);
//p_kreis->Zeichnen();

p1.set(100+50*s45,100+50*s45);
p2.set(100-50*s45,100-50*s45);
p_linie = new CLinie(101,p1, p2);
db->addObject(p_linie);
//p_linie->Zeichnen();

p1.set(100+50*s45,100-50*s45);
p2.set(100-50*s45,100+50*s45);
p_linie = new CLinie(102,p1, p2);
db->addObject(p_linie);
//p_linie->Zeichnen();



// Figur 2
mp.set(300,100);
p_kreis = new CKreis(201,mp,25);
db->addObject(p_kreis);
//p_kreis->Zeichnen();
p_kreis = new CKreis(202,mp,50);
db->addObject(p_kreis);
//p_kreis->Zeichnen();

// Figur 3 (von unten nach oben)
float x1=150, x2=250, y=200;
for (int i=301; i<=304; i++)
	{
		p1.set(x1,y); p2.set(x2,y);
		p_linie = new CLinie(i,p1,p2);
		db->addObject(p_linie);
		//p_linie->Zeichnen();
		y = y + 25;
	}
db->redraw();
AfxMessageBox("Initial Zeichnung");
db->searchObject(101)->löscheGrafik();
db->searchObject(102)->löscheGrafik();
db->searchObject(103)->löscheGrafik();
db->searchObject(302)->löscheGrafik();
db->searchObject(303)->löscheGrafik();
AfxMessageBox("Grafik 1 und 2 mittlere Linien aus Grafik 3 gelöscht");
db->searchObject(201)->löscheGrafik();
db->searchObject(202)->löscheGrafik();
db->searchObject(301)->löscheGrafik();
db->searchObject(304)->löscheGrafik();
AfxMessageBox("Alles gelöscht");
db->redraw();
AfxMessageBox("Redraw");

CVektor* dVektor;
CPunkt* center;
dVektor = new CVektor(200,130);
db->searchObject(101)->schieben(dVektor);
db->searchObject(102)->schieben(dVektor);
db->searchObject(103)->schieben(dVektor);

center = new CPunkt();
center->set(150,200);
db->searchObject(301)->drehen(center, 360-45);
db->searchObject(302)->drehen(center, 360-45);
db->searchObject(303)->drehen(center, 360-45);
db->searchObject(304)->drehen(center, 360-45);

center->set(300,300);
db->searchObject(101)->drehen(center, 45);
db->searchObject(102)->drehen(center, 45);
db->searchObject(103)->drehen(center, 45);

dVektor->set(-150,100);
db->searchObject(201)->schieben(dVektor);
db->searchObject(202)->schieben(dVektor);

//Objekte löschen sonst segment fehler
db->searchObject(101)->löscheGrafik();
db->searchObject(102)->löscheGrafik();
db->searchObject(103)->löscheGrafik();
db->searchObject(302)->löscheGrafik();
db->searchObject(303)->löscheGrafik();
db->searchObject(201)->löscheGrafik();
db->searchObject(202)->löscheGrafik();
db->searchObject(301)->löscheGrafik();
db->searchObject(304)->löscheGrafik();
db->redraw();

AfxMessageBox("Figuren bewegt");

db->searchObject(301)->löscheGrafik();
db->searchObject(302)->löscheGrafik();
db->searchObject(303)->löscheGrafik();
db->searchObject(304)->löscheGrafik();

// Ende
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
