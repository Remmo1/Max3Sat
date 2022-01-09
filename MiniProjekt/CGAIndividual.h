#pragma once
#include <iostream>
#include "CMax3SatProblem.h"

class CGAIndividual
{
private:
	bool* genotype;
	int fitness;
	const int PROBLEMSIZE = 50;
	const int AMOUNTOFCLAUSES = 213;

public:
	CGAIndividual(bool value);

	CGAIndividual(bool* newGen);

	bool** crossover(CGAIndividual& other);
	void mutation(int probability);
	int getFitness(CMax3SatProblem problem);
	bool* getGenotype();

	void showGenotype();

};

