#include "manage_particle.h"
#include <random>
#include<stdexcept>

std::random_device Rand;
std::mt19937 mt(Rand());
std::uniform_int_distribution<> rndx(300, 900);
std::uniform_int_distribution<> rndy(300, 700);
std::uniform_int_distribution<> rnds(0, 900);

manage_particle::manage_particle() : state(false), particles(600) {
	particle = new Particle[particles];
}

manage_particle::~manage_particle() {
	delete[] particle;
}

void manage_particle::init() {
	int x = rndx(mt);
	int y = rndy(mt);
	for (int i = 0; i < particles; i++) {
		particle[i].setPosition(x, y);
		particle[i].init();
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