#pragma once
class CPunkt
{
public:
	CPunkt(void);
	~CPunkt(void);
	void set(float, float);
	float getX();
	float getY();
private:
	float m_x,m_y;
};

