#include "CGAIndividual.h"
#include <ctime>
#include <random>
#include <sstream>

// konsturktor bezparametrowy
CGAIndividual::CGAIndividual() {
	genotype = NULL;
}

// mo¿na podaæ do konstruktora wartoœæ true/false, wtedy ca³y jego genotyp taki bêdzie
CGAIndividual::CGAIndividual(bool value) {
	genotype = new bool[PROBLEMSIZE];

	for (int i = 0; i < PROBLEMSIZE; i++)
		genotype[i] = value;
}

// mo¿na podaæ do konstruktora nowy genotyp jako tablice
CGAIndividual::CGAIndividual(bool* newGen) {
	if (genotype != NULL)
		delete[] genotype;
	genotype = newGen;
}

// konstruktor kopiuj¹cy 
CGAIndividual::CGAIndividual(const CGAIndividual& other) {
	if (genotype != NULL)
		delete[] genotype;

	bool* newGenotype = new bool[PROBLEMSIZE];

	for (int i = 0; i < PROBLEMSIZE; i++)
		newGenotype[i] = other.genotype[i];

	genotype = newGenotype;
}

// destruktor
CGAIndividual::~CGAIndividual() {
	delete[] genotype;
}

// ================== metody z instrukcji =======================
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

int CGAIndividual::getFitness(std::vector<Clause*> clauses, CMax3SatProblem problem) {
	return problem.compute(genotype, AMOUNTOFCLAUSES, clauses);
}

// =============== metody dodatkowe ================

bool* CGAIndividual::getGenotype() {
	return genotype;
}

void CGAIndividual::showGenotype() {
	for (int i = 0; i < PROBLEMSIZE; i++) {
		int a = genotype[i] == true ? 1 : 0;
		std::cout << a;
	}
	std::cout<<std::endl;
}