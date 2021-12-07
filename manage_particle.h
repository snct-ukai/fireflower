#pragma once
#include "Particle.h"

class manage_particle
{
private:
	int particles;
	Particle* particle;
public:
	bool state;
	manage_particle();
	void update();
	void init();
	void draw();
	void setHDC(HDC hdc);
	void clean();
	~manage_particle();
};