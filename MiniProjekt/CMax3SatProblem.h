#pragma once
#include "Clause.h"
#include <iostream>
#include <vector>

class CMax3SatProblem
{
public:
	std::vector<Clause*> load(int amountOfClauzules, std::string file);
	int compute(bool* solution, int amountOfClauzules, std::vector<Clause*>& clauzles);
};

