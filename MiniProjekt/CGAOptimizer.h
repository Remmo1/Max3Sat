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

	std::vector<CGAIndividual*> population;

	CMax3SatProblem problem;


public:
	CGAOptimizer(int populationQuantity, int probabilityCrossing, int probabilityMutation, CMax3SatProblem problem);
	~CGAOptimizer();

	bool initialize();
	std::vector<CGAIndividual*> runIteration();

	void showPopulation();

};

