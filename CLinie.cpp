#include "StdAfx.h"
#include <iostream>
#define M_PI 3.14159265
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
	//cout << "Punkt1 x: " << m_ap.getX() << " y: " << m_ap.getY() << " Punkt2 x: " << m_ep.getX() << " y: " << m_ep.getY() << endl;

	Gpoint mp[2] = {{m_ap.getX(), m_ap.getY()}, {m_ep.getX(), m_ep.getY()}};

	Gpoint_list linie;

	linie.points = mp;
	linie.num_points = 2;
	
	gs.gcreate_seg(m_iObjNr);
	gs.gpolyline(&linie);
	gs.gclose_seg();
}

void CLinie::schieben(CVektor* dVektor)
{
	m_ap.set(m_ap.getX() + dVektor->get_a(), m_ap.getY() + dVektor->get_b());
	m_ep.set(m_ep.getX() + dVektor->get_a(), m_ep.getY() + dVektor->get_b());
}

void CLinie::drehen(CPunkt* center, float range)
{
	range = range * (M_PI / 180);
	m_ap.set(m_ap.getX() - center->getX(), m_ap.getY() - center->getY());
	m_ep.set(m_ep.getX() - center->getX(), m_ep.getY() - center->getY());
	m_ap.set(m_ap.getX() * cos(range) - m_ap.getY() * sin(range), m_ap.getX() * sin(range) + m_ap.getY() * cos(range));
	m_ep.set(m_ep.getX() * cos(range) - m_ep.getY() * sin(range), m_ep.getX() * sin(range) + m_ep.getY() * cos(range));
	m_ap.set(m_ap.getX() + center->getX(), m_ap.getY() + center->getY());
	m_ep.set(m_ep.getX() + center->getX(), m_ep.getY() + center->getY());
}
