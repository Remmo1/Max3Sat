#pragma once
#include <iostream>
#include "CMax3SatProblem.h"

class CGAIndividual
{
private:
	bool* genotype;
	const int PROBLEMSIZE = 50;
	const int AMOUNTOFCLAUSES = 213;

public:
	// konstruktory 
	CGAIndividual();
	CGAIndividual(bool value);
	CGAIndividual(bool* newGen);
	CGAIndividual(const CGAIndividual& other);

	// destruktor
	~CGAIndividual();

	// metody z instrukcji
	bool** crossover(CGAIndividual& other);
	void mutation(int probability);
	int getFitness(std::vector<Clause*> clauses, CMax3SatProblem problem);

	// zwraca genotyp (wskaünik na niego)
	bool* getGenotype();

	// pokazuje genotyp na ekranie w formacie 0101010010101
	void showGenotype();

};

