#pragma once

class CGrafikDialog
{
public:
	CGrafikDialog(void);
	~CGrafikDialog(void);
	void PickeObjekt(int*);
	void EingabePunkt(char*, CPunkt*);	
	void Message(char*);
	int MenueWahl();
};
