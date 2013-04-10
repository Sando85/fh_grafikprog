#pragma once

class CVektor : public CObject
{
public:
	CVektor(void);
	CVektor(float, float);
	~CVektor(void);
	void set(float, float);
	float get_a();
	float get_b();

private:
	float m_a;
	float m_b;
};

