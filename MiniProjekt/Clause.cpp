#include "Clause.h"
#include <iostream>

Clause::Clause() {
	st = 0;
	nd = 0;
	rd = 0;
}

Clause::Clause(int _st, int _nd, int _rd) {
	st = _st;
	nd = _nd;
	rd = _rd;
}

Clause::~Clause() {

}

void Clause::show() {
	std::cout << st << ", " << nd << ", " << rd << std::endl;
}

int Clause::getSt() {
	return st;
}

int Clause::getNd() {
	return nd;
}

int Clause::getRd() {
	return rd;
}

void Clause::setSt(int _st) {
	st = _st;
}

void Clause::setNd(int _nd) {
	nd = _nd;
}

void Clause::setRd(int _rd) {
	rd = _rd;
}