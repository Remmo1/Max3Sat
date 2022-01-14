#pragma once
#include <vector>
#include <ctime>
#include <random>
#include "CGAIndividual.h"
#include "CMax3SatProblem.h"


class CGAOptimizer
{
private:
	int populationQuantity;
	int probabilityCrossing;
	int probabilityMutation;

	const int PROBLEMSIZE = 50;
	const int AMOUNTOFCLAUSES = 213;
	const int TOURNAMENTSIZE = 2;

	std::vector<CGAIndividual*> population;
	std::vector<Clause*> clauses;

	CMax3SatProblem problem;


public:
	CGAOptimizer(int populationQuantity, int probabilityCrossing, int probabilityMutation, CMax3SatProblem problem);
	~CGAOptimizer();

	bool initialize(std::string fileName);
	CGAIndividual* tournament(std::vector<CGAIndividual*> somePopulation);
	void runIteration();

	void showPopulation();
	void showBestInPopulation();
};

