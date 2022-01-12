#include "Clause.h"
#include <iostream>

Clause::Clause() {
	this->st = 0;
	this->nd = 0;
	this->rd = 0;
}

Clause::Clause(int st, int nd, int rd) {
	this->st = st;
	this->nd = nd;
	this->rd = rd;
}

Clause::~Clause() {

}

void Clause::show() {
	std::cout << this->st << ", " << this->nd << ", " << this->rd << std::endl;
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

void Clause::setSt(int st) {
	this->st = st;
}

void Clause::setNd(int nd) {
	this->nd = nd;
}

void Clause::setRd(int rd) {
	this->rd = rd;
}