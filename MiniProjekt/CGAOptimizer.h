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
	// konstruktor i destruktor
	CGAOptimizer(int _populationQuantity, int _probabilityCrossing, int _probabilityMutation, CMax3SatProblem _problem);
	~CGAOptimizer();

	// metoda która tworzy losow¹ populacjê i otwiera plik
	// rzuca false jeœli pliku nie da³o siê otworzyæ
	bool initialize(std::string fileName);

	// metoda wyboru rodzica spoœród TOURNAMENTSIZE osobników dla populacji somePopulation
	CGAIndividual* tournament(std::vector<CGAIndividual*> somePopulation);

	// pojedyncza iteracja okreœlona w instrukcji
	void runIteration();

	// metody dodatkowe:
	
	// pokazuje wszystkie osobniki w populacji
	void showPopulation();
	// pokazuje najlepszego osobnika 
	void showBestInPopulation();
};

