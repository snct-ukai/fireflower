#pragma once
#include "manage_particle.h"

class manage_fireflower
{
private:
	manage_particle* particle;
	unsigned int num;
public:
	manage_fireflower(int num);
	void update();
	void init();
	void draw();
	void setHDC(HDC hdc);
	void clean();
	~manage_fireflower();
};