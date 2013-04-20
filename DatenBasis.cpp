#include "StdAfx.h"
#include "datenbasis.h"
#include "Drawable.h"

CDatenBasis::CDatenBasis(void)
{
}

CDatenBasis::~CDatenBasis(void)
{
}

void CDatenBasis::addObject(CGeoObject* pObject)
{
	m_oaDatenBasis.Add(pObject);
}

void CDatenBasis::deleteObject(CGeoObject* delObj)
{
	CGeoObject* pObject;
	int iCount = (int)m_oaDatenBasis.GetCount();
	for (int iPos = 0; iPos < iCount; iPos++)
	{
		// Zeiger auf das Objekt bereitstellen
		pObject = (CGeoObject*) m_oaDatenBasis[iPos];
		if (pObject == delObj)
		{
			pObject->LoescheGrafik();  // Grafik löschen
			m_oaDatenBasis.RemoveAt(iPos);  // Objekt aus Datenbasis entfernen
			delete pObject; // Speicherplatz freigeben
			break;
		}
	}
}

CGeoObject* CDatenBasis::searchObject(int ObjNr)
{
	CGeoObject* pObject;
	CGeoObject* pReturnObject = NULL;
	int iCount = (int)m_oaDatenBasis.GetCount();
	for (int iPos = 0; iPos < iCount; iPos++)
	{
		// Zeiger auf das Objekt bereitstellen
		pObject = (CGeoObject*) m_oaDatenBasis[iPos];
		if (pObject->getObjNr() == ObjNr)
		{
			pReturnObject = pObject;
			break;
		}	
	}
	return pReturnObject;	
}

void CDatenBasis::redraw()
{
	// Wichtiger Hinweis:
	// Vor Aufruf dieser Methode müssen sämtliche GRAFIK-Objekte gelöscht werden.
	// Ansonsten gibt es (zumindest im GKS wegen der Segmente) Probleme beim wiederholten
	// Anlegen der Grafikobjekte.
	// **********************************************************************************
	CGeoObject* pObject;
	int iCount = (int)m_oaDatenBasis.GetCount();
	// Gibt es Elemente in der Datenbasis?
	if (iCount > 0)
	{
		for (int iPos = 0; iPos < iCount; iPos++)
		{
			// Zeiger auf das Objekt bereitstellen
			pObject = (CGeoObject*) m_oaDatenBasis[iPos];
			// Zeichnen
			//pObject->Zeichnen();
		}
	}
	else AfxMessageBox("Keine Objekte vorhanden");
}
