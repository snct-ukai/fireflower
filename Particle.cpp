#include "Particle.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>

Particle::Particle(void) : x(0), y(0), vx(0), vy(0), ax(0), ay(0), omega(0), phi(0), radius(0), mx(0), my(0), lastupdate(0), life(0), color(0){}
Particle::~Particle(void) {

}
void Particle::init(void) {
	double vec = rand() * 40;
	double rad = rand() * 2 * M_PI;
	x = mx;
	y = my;
	vx = vec * cos(rad);
	vy = vec * sin(rad);
	ax = 0;
	ay = 9.8;
	radius = 10;
	life = 5;
	color = RGB(0, 0, 255);
	timer.reset();
	lastupdate = 0;
}
void Particle::clean(void) {
	x = y = mx = my = vx = vy = ax = ay = radius = life = color = lastupdate = 0;
}
void Particle::update(void) {
	double t = timer.get();
	if (t < life) {
		double dt = t - lastupdate;
		vx += ax * dt;
		vy += ay * dt;
		x += vx * dt;
		y += vy * dt;
		double RG = 255 * t / life;
		lastupdate = timer.get();
	}
	else {
		throw std::logic_error("die");
		clean();
	}
}
void Particle::draw(void) {
	SelectObject(hdc, GetStockObject(DC_PEN));
	SelectObject(hdc, GetStockObject(DC_BRUSH));
	SetDCPenColor(hdc, color);
	SetDCBrushColor(hdc, color);
	Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
}
void Particle::setCursorPos(int mx, int my) {
	this->mx = mx;
	this->my = my;
}
void Particle::setHDC(HDC hdc) {
	this->hdc = hdc;
}
void Particle::setPosition(int x, int y) {
	mx = x;
	my = y;
}
double Particle::rand(void) {
	return static_cast<double>(::rand()) / RAND_MAX;
}