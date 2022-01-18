#pragma once
#include "Clause.h"
#include <iostream>
#include <vector>

class CMax3SatProblem
{
public:
	// metoda zwraca wektor klauzul (wskaŸników na nie) odczytanych z pliku o nazwie filename
	std::vector<Clause*> load(int amountOfClauses, std::string filename);

	// metoda zwraca jakoœæ rozwi¹zania solution
	int compute(bool* solution, int amountOfClauses, std::vector<Clause*>& clauses);
};

