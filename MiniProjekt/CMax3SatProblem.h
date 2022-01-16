#pragma once
#include "Clause.h"
#include <iostream>
#include <vector>

class CMax3SatProblem
{
public:
	std::vector<Clause*> load(int amountOfClauses, std::string file);
	int compute(bool* solution, int amountOfClauses, std::vector<Clause*>& clauzles);
};

