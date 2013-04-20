#include "stdafx.h"
#include "grafikdialog.h"

CGrafikDialog::CGrafikDialog(void)
{
}

CGrafikDialog::~CGrafikDialog(void)
{
}

void CGrafikDialog::PickeObjekt(int* ObjNr)
{
	printf("\n Objekt waehlen:");
	scanf("%i", ObjNr);
}

void CGrafikDialog::EingabePunkt(char* text, CPunkt* Punkt)
{
	float x,y;
	printf("\n %s",text);
	scanf("%f,%f", &x, &y);
	Punkt->set(x,y);
}

void CGrafikDialog::Message(char* text)
{
	printf("\n %s",text);
}

int CGrafikDialog::MenueWahl()
{
	int wahl;
	printf("\n Befehl waehlen;");
	printf("\n 1: Linie zeichnen");
	printf("\n 2: Objekt loeschen");
	printf("\n 0: Programm beenden");
	printf("\n\n Ihre Wahl: ");
	scanf("%i", &wahl);
	return wahl; 
}


