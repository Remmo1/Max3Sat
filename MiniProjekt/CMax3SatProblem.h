#pragma once
#include "Clause.h"
#include <iostream>
#include <vector>

class CMax3SatProblem
{
public:
	std::vector<Clause*> load(int amountOfClauzules, std::string file);
	int compute(std::string solution, int amountOfClauzules, std::vector<Clause*>& clauzles);
};

