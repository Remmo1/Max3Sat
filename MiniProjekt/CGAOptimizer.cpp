#include "CGAOptimizer.h"


CGAOptimizer::CGAOptimizer(int populationQuantity, int probabilityCrossing, int probabilityMutation, CMax3SatProblem problem) {
	this->populationQuantity = populationQuantity;
	this->probabilityCrossing = probabilityCrossing;
	this->probabilityMutation = probabilityMutation;
	this->problem = problem;
}

bool CGAOptimizer::initialize() {
	srand(time(NULL));

	for (int i = 0; i < populationQuantity; i++) {
		bool* gens = new bool[PROBLEMSIZE];

		for (int j = 0; j < PROBLEMSIZE; j++) {
			int random = std::rand() % 2;
			gens[j] = random;
		}

		population.push_back(new CGAIndividual(gens));
	}

	return population.empty() ? false : true;
}

void CGAOptimizer::showPopulation() {
	for (int i = 0; i < populationQuantity; i++)
		population.at(i)->showGenotype();
}

std::vector<CGAIndividual*> CGAOptimizer::runIteration() {
	srand(time(NULL));

	std::vector<CGAIndividual*> newPopulation;

	CGAIndividual* father;
	CGAIndividual* mother;
	CGAIndividual* child1;
	CGAIndividual* child2;

	while (newPopulation.size() < population.size()) {
		// wybór ojca
		CGAIndividual* fatherCandidate1 = population.at(std::rand() % populationQuantity);
		CGAIndividual* fatherCandidate2 = population.at(std::rand() % populationQuantity);

		father = fatherCandidate1->getFitness(problem) > fatherCandidate2->getFitness(problem) ? fatherCandidate1 : fatherCandidate2;

		// wybór matki
		CGAIndividual* motherCandidate1 = population.at(std::rand() % populationQuantity);
		CGAIndividual* motherCandidate2 = population.at(std::rand() % populationQuantity);

		mother = motherCandidate1->getFitness(problem) > motherCandidate2->getFitness(problem) ? motherCandidate1 : motherCandidate2;

		// sprawdzenie czy krzy¿ujemy
		int probability = (std::rand() % 100) + 1;

		// krzy¿owanie genów jeœli wartoœæ mniejsza
		if (probability < probabilityCrossing) {
			bool** children = father->crossover(*mother);
			child1 = new CGAIndividual(children[0]);
			child2 = new CGAIndividual(children[1]);

			// mutacje
			child1->mutation(probabilityMutation);
			child2->mutation(probabilityMutation);

			// dodatnie dzieciacków do populacji
			newPopulation.push_back(child1);
			newPopulation.push_back(child2);
		}
		
		// wrzucenie kopii jeœli wartoœæ mniejsza
		else {
			newPopulation.push_back(father);
			newPopulation.push_back(mother);
		}
		
	}

	population = newPopulation;
	return newPopulation;
}