#include "manage_fireflower.h"

manage_fireflower::manage_fireflower(int num): num(num) {
	particle = new manage_particle[this->num];
	particle[0].state = true;
}

void manage_fireflower::init() {
	for (int i = 0; i < num; i++) {
		particle[i].init();
	}
}

void manage_fireflower::update() {
	for (int i = 0; i < num; i++) {
		particle[i].update();
	}
}

void manage_fireflower::draw() {
	for (int i = 0; i < num; i++) {
		particle[i].draw();
	}
}

void manage_fireflower::setHDC(HDC hdc) {
	for (int i = 0; i < num; i++) {
		particle[i].setHDC(hdc);
	}
}

void manage_fireflower::clean() {
	for (int i = 0; i < num; i++) {
		particle[i].clean();
	}
}

manage_fireflower::~manage_fireflower() {
	delete[] particle;
}
