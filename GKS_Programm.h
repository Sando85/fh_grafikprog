#pragma once
#include "GServer.h"
#include "Helper\Helper\Vector.h"
#include "Klassen\Punkt.h"

extern CServer gs;

class CDatabase;
class CVector;
class CPunkt;


class CGKS_Programm //: public CServer
{

public:
	CGKS_Programm(void);
	~CGKS_Programm(void);
	void execute();
	void startGKS(void);
	void stopGKS(void);
	void deleteObject(int id);
	void move(int objId, int dx, int dy,CPunkt base);
	void rotate(int objId, int angle,const CPunkt base);
	void scale(int objId, float xFactor, float yFactor,CPunkt base);

private:
	CDatabase* db;
	
	
};
#pragma once

#include "resource.h"

