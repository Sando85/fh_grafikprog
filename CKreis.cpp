#include "StdAfx.h"
//#include <iostream>
//using namespace std;
extern CServer gs;

CKreis::CKreis(int id, CPunkt mp, float radius)
{
	m_iObjNr = id;
	m_mp = mp;
	m_radius = radius;	
}

CKreis::CKreis(int id, CPunkt mp, CPunkt pp)
{
	m_iObjNr = id;
	m_mp = mp;
	m_radius = sqrt(pow(m_mp.getX() - pp.getX(), 2) + pow(m_mp.getY() - pp.getY(), 2));
}


CKreis::~CKreis(void)
{
}

void CKreis::Zeichnen()
{
	Gpoint mp[2] = {{m_mp.getX(), m_mp.getY()}, {m_mp.getX(),  m_mp.getY() + m_radius}};
	Gpoint_list kreis;
//	cout << "Punkt x: " << m_mp.getX() << " y: " << m_mp.getY() << " radius: " << m_radius << endl;
	kreis.num_points = 2;
	kreis.points = mp;

	gs.gx_circle(&kreis);
}
