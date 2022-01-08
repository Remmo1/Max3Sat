#include "Clause.h"
#include <iostream>

Clause::Clause() {
	this->st = 0;
	this->nd = 0;
	this->rd = 0;
	this->stV = false;
	this->ndV = false;
	this->rdV = false;
}

Clause::Clause(int st, int nd, int rd) {
	this->st = st;
	this->nd = nd;
	this->rd = rd;

	if (st > 0) stV = true; else stV = false;
	if (nd > 0) ndV = true; else ndV = false;
	if (rd > 0) rdV = true; else rdV = false;
}

Clause::Clause(int st, int nd, int rd, bool stV, bool ndV, bool rdV) {
	this->st = st;
	this->nd = nd;
	this->rd = rd;
	this->stV = stV;
	this->ndV = ndV;
	this->rdV = rdV;
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

int Clause::getStV() {
	return stV;
}

int Clause::getNdV() {
	return ndV;
}

int Clause::getRdV() {
	return rdV;
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

void Clause::setStV(bool v) {
	this->stV = v;
}

void Clause::setNdV(bool v) {
	this->ndV = v;
}

void Clause::setRdV(bool v) {
	this->rdV = v;
}