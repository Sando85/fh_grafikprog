#include "StdAfx.h"
#include "GKS_Programm.h"

extern CServer gs;

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
p_kreis->Zeichnen();

p1.set(100+50*s45,100+50*s45);
p2.set(100-50*s45,100-50*s45);
p_linie = new CLinie(101,p1, p2);
p_linie->Zeichnen();

p1.set(100+50*s45,100-50*s45);
p2.set(100-50*s45,100+50*s45);
p_linie = new CLinie(102,p1, p2);
p_linie->Zeichnen();



// Figur 2
mp.set(300,100);
p_kreis = new CKreis(201,mp,25);
p_kreis->Zeichnen();
p_kreis = new CKreis(202,mp,50);
p_kreis->Zeichnen();

// Figur 3 (von unten nach oben)
float x1=150, x2=250, y=200;
for (int i=301; i<=304; i++)
	{
		p1.set(x1,y); p2.set(x2,y);
		p_linie = new CLinie(i,p1,p2);
		p_linie->Zeichnen();
		y = y + 25;
	} 
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
