#pragma once

class CMatrix
{
public:
	CMatrix(int i=0, int j=0, float def=0);
	CMatrix(int i, int j, float values[], int elementCount);
	~CMatrix(void);

//	CMatrix* operator*(CMatrix* A) const;

	float getValueAt(int i,int j) const;
	virtual void setElement(int i,int j, int value);
	void setMatrix(float values[], int elementCount);
	int getRowCount() const;
	int getColumnCount() const;

	
private:
	void init(int i, int j, float def[], int elementCount);
	void init(int i, int j, float def);
	int getElementCount() const;
	int imax;
	int jmax;
	float* matrix;

};

CMatrix operator*(CMatrix A, CMatrix B);
