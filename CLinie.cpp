#include "StdAfx.h"
#include <iostream>
using namespace std;

extern CServer gs;

CLinie::CLinie(int id, CPunkt ap, CPunkt ep)
{
	m_iObjNr = id;
	m_ap = ap;
	m_ep = ep;
}


CLinie::~CLinie(void)
{
}

CPunkt CLinie::getAP()
{
	return m_ap;
}

CPunkt CLinie::getEP()
{
	return m_ep;
}

void CLinie::Zeichnen()
{
	cout << "Punkt1 x: " << m_ap.getX() << " y: " << m_ap.getY() << " Punkt2 x: " << m_ep.getX() << " y: " << m_ep.getY() << endl;

	Gpoint mp[2] = {{m_ap.getX(), m_ap.getY()}, {m_ep.getX(), m_ep.getY()}};

	Gpoint_list linie;

	linie.points = mp;
	linie.num_points = 2;
	
	gs.gpolyline(&linie);
}
