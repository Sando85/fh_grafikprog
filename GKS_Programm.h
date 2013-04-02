#pragma once
#include "GServer.h"

extern CServer gs;

class CDatabase;

class CGKS_Programm //: public CServer
{

public:
	CGKS_Programm(void);
	~CGKS_Programm(void);
	void execute();
	void startGKS(void);
	void stopGKS(void);
	void deleteObject(int id);

private:
	CDatabase* db;
	
	
};
#pragma once

#include "resource.h"

