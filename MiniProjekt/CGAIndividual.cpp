#include "CGAIndividual.h"
#include <ctime>
#include <random>
#include <sstream>

CGAIndividual::CGAIndividual(bool value) {
	genotype = new bool[PROBLEMSIZE];

	for (int i = 0; i < PROBLEMSIZE; i++)
		genotype[i] = value;
}

CGAIndividual::CGAIndividual(bool* newGen) {
	genotype = newGen;
}

bool** CGAIndividual::crossover(CGAIndividual& other) {
	srand(time(NULL));

	int randomIndex;
	bool** result = new bool* [2];

	for (int i = 0; i < 2; i++) {
		result[i] = new bool[PROBLEMSIZE];
	}

	for (int i = 0; i < PROBLEMSIZE; i++) {
		randomIndex = std::rand() % 2;

		if (randomIndex == 0) {
			result[0][i] = this->genotype[i];
			result[1][i] = other.genotype[i];
		}
		else {
			result[0][i] = other.genotype[i];
			result[1][i] = this->genotype[i];
		}
	}

	return result;
}

void CGAIndividual::mutation(int probability) {
	int randomVariable;

	for (int i = 0; i < PROBLEMSIZE; i++) {
		randomVariable = ( std::rand() % 100 ) + 1;

		if (randomVariable < probability)
			genotype[i] = !genotype[i];
	}
}

bool* CGAIndividual::getGenotype() {
	return genotype;
}

int CGAIndividual::getFitness(CMax3SatProblem problem) {
	std::vector<Clause*> clauses = problem.load(213, "m3s_50_14.txt");

	std::stringstream solution;

	for (int i = 0; i < PROBLEMSIZE; i++) {
		if (genotype[i])
			solution << '1';
		else
			solution << '0';
	}

	return problem.compute(solution.str(), AMOUNTOFCLAUSES, clauses);
}

void CGAIndividual::showGenotype() {
	for (int i = 0; i < PROBLEMSIZE; i++) {
		int a = genotype[i] == true ? 1 : 0;
		std::cout << a;
	}
	std::cout<<std::endl;
}