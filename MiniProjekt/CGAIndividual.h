#pragma once
#include <iostream>
#include "CMax3SatProblem.h"

class CGAIndividual
{
private:
	bool* genotype;
	int fitness = 0;
	const int PROBLEMSIZE = 50;
	const int AMOUNTOFCLAUSES = 213;

public:
	CGAIndividual();
	CGAIndividual(bool value);
	CGAIndividual(bool* newGen);
	CGAIndividual(const CGAIndividual& other);

	~CGAIndividual();

	bool** crossover(CGAIndividual& other);
	void mutation(int probability);
	int getFitness(std::vector<Clause*> clauses, CMax3SatProblem problem);

	bool* getGenotype();

	void showGenotype();

};

