#include "StdAfx.h"
#define M_PI 3.14159265

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

	gs.gcreate_seg(m_iObjNr);
	gs.gx_circle(&kreis);
	gs.gclose_seg();
}

void CKreis::schieben(CVektor* dVektor)
{
	m_mp.set(m_mp.getX() + dVektor->get_a(), m_mp.getY() + dVektor->get_b());
}

void CKreis::drehen(CPunkt* center, float range)
{
	range = range * (M_PI / 180);
	m_mp.set(m_mp.getX() - center->getX(), m_mp.getY() - center->getY());
	m_mp.set(m_mp.getX() * cos(range) - m_mp.getY() * sin(range), m_mp.getX() * sin(range) + m_mp.getY() * cos(range));
	m_mp.set(m_mp.getX() + center->getX(), m_mp.getY() + center->getY());
}
