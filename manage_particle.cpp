#include "manage_particle.h"
#include <random>
#include<stdexcept>

std::random_device Rand;
std::mt19937 mt(Rand());
std::uniform_int_distribution<> rndx(300, 1300);
std::uniform_int_distribution<> rndy(300, 700);
std::uniform_int_distribution<> rnds(0, 900);
std::uniform_int_distribution<> hsv(0, 360);

manage_particle::manage_particle() : state(false), particles(500) {
	particle = new Particle[particles];
}

manage_particle::~manage_particle() {
	delete[] particle;
}

void manage_particle::init() {
	int x = rndx(mt);
	int y = rndy(mt);

	double h = hsv(mt);
	const double v = 70;
	double max = 255 * v / 100;
	double r = 0;
	double g = 0;
	double b = 255 * v / 100;
	int hrad = h / 60;
	switch (hrad) {
	case 0:
	case 6:
		if (h == 360)
			h = 0;
		r = max;
		g = max * h / 60;
		b = 0;
		break;
	case 1:
		r = max * (120 - h) / 60;
		g = max;
		b = 0;
		break;
	case 2:
		r = 0;
		g = max;
		b = max * (h - 120) / 60;
		break;
	case 3:
		r = 0;
		g = max;
		b = max * (240 - h) / 60;
		break;
	case 4:
		r = max * (h - 240) / 60;
		g = max;
		b = 0;
		break;
	case 5:
		r = max;
		g = max * (360 - h) / 60;
		b = 0;
		break;
	}
	for (int i = 0; i < particles; i++) {
		particle[i].setPosition(x, y);
		particle[i].init();
		particle[i].setColor(r, g, b);
	}
	state = rndx(mt) == 300;
}

void manage_particle::update() {
	if (state) {
		try {
			for (int i = 0; i < particles; i++) {
				particle[i].update();
			}
		}
		catch (std::exception e) {
			state = false;
			clean();
			init();
		}
	}
	else {
		clean();
		init();
	}
}

void manage_particle::draw() {
	if (state) {
		for (int i = 0; i < particles; i++) {
			particle[i].draw();
		}
	}
}

void manage_particle::setHDC(HDC hdc) {
	for (int i = 0; i < particles; i++) {
		particle[i].setHDC(hdc);
	}
}

void manage_particle::clean() {
	for (int i = 0; i < particles; i++) {
		particle[i].clean();
	}
}