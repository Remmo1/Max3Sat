#include "CGAIndividual.h"
#include <ctime>
#include <random>
#include <sstream>


CGAIndividual::CGAIndividual() {
	genotype = NULL;
}

CGAIndividual::CGAIndividual(bool value) {
	genotype = new bool[PROBLEMSIZE];

	for (int i = 0; i < PROBLEMSIZE; i++)
		genotype[i] = value;
}


CGAIndividual::CGAIndividual(bool* newGen) {
	if (genotype != NULL)
		delete[] genotype;
	genotype = newGen;
}

CGAIndividual::CGAIndividual(const CGAIndividual& other) {
	if (genotype != NULL)
		delete[] genotype;

	bool* newGenotype = new bool[PROBLEMSIZE];

	for (int i = 0; i < PROBLEMSIZE; i++)
		newGenotype[i] = other.genotype[i];

	genotype = newGenotype;
}

CGAIndividual::~CGAIndividual() {
	delete[] genotype;
}

bool** CGAIndividual::crossover(CGAIndividual& other) {
	srand(time(NULL));

	int randomIndex;
	bool** result = new bool * [2];

	for (int i = 0; i < 2; i++) 
		result[i] = new bool[PROBLEMSIZE];

	for (int i = 0; i < PROBLEMSIZE; i++) {
		randomIndex = std::rand() % 2;

		if (randomIndex == 0) {
			result[0][i] = genotype[i];
			result[1][i] = other.genotype[i];
		}
		else {
			result[0][i] = other.genotype[i];
			result[1][i] = genotype[i];
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

int CGAIndividual::getFitness(std::vector<Clause*> clauses, CMax3SatProblem problem) {
	return problem.compute(genotype, AMOUNTOFCLAUSES ,clauses);
}

void CGAIndividual::showGenotype() {
	for (int i = 0; i < PROBLEMSIZE; i++) {
		int a = genotype[i] == true ? 1 : 0;
		std::cout << a;
	}
	std::cout<<std::endl;
}