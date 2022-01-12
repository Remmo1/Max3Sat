#include "CGAOptimizer.h"


CGAOptimizer::CGAOptimizer(int populationQuantity, int probabilityCrossing, int probabilityMutation, CMax3SatProblem problem) {
	this->populationQuantity = populationQuantity;
	this->probabilityCrossing = probabilityCrossing;
	this->probabilityMutation = probabilityMutation;
	this->problem = problem;
}

CGAOptimizer::~CGAOptimizer() {
	for (int i = 0; i < population.size(); i++) {
		delete population[i];
		delete clauses[i];
	}
}

bool CGAOptimizer::initialize(std::string fileName) {
	srand(time(NULL));

	// otworzenie pliku
	clauses = problem.load(AMOUNTOFCLAUSES, fileName);

	// tworzenie losowej populacji
	for (int i = 0; i < populationQuantity; i++) {
		bool* gens = new bool[PROBLEMSIZE];

		for (int j = 0; j < PROBLEMSIZE; j++) {
			int random = std::rand() % 2;
			gens[j] = random;
		}

		population.push_back(new CGAIndividual(gens));
	}

	// sprawdzenie czy otworzenie pliku siê uda³o
	return clauses.empty() ? false : true;
}

void CGAOptimizer::showPopulation() {
	for (int i = 0; i < populationQuantity; i++)
		population.at(i)->showGenotype();
}

std::vector<CGAIndividual*> CGAOptimizer::runIteration() {
	srand(time(NULL));

	std::vector<CGAIndividual*> newPopulation;

	CGAIndividual* father = NULL;
	CGAIndividual* mother = NULL;
	CGAIndividual* child1 = NULL;
	CGAIndividual* child2 = NULL;

	while (newPopulation.size() < population.size()) {
		// wybór ojca
		CGAIndividual* fatherCandidate1 = population.at(std::rand() % populationQuantity);
		CGAIndividual* fatherCandidate2 = population.at(std::rand() % populationQuantity);

		father = fatherCandidate1->getFitness(clauses, problem) > fatherCandidate2->getFitness(clauses, problem) ? fatherCandidate1 : fatherCandidate2;

		// wybór matki
		CGAIndividual* motherCandidate1 = population.at(std::rand() % populationQuantity);
		CGAIndividual* motherCandidate2 = population.at(std::rand() % populationQuantity);

		mother = motherCandidate1->getFitness(clauses, problem) > motherCandidate2->getFitness(clauses, problem) ? motherCandidate1 : motherCandidate2;

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
			child1 = new CGAIndividual(*father);
			child2 = new CGAIndividual(*mother);

			newPopulation.push_back(child1);
			newPopulation.push_back(child2);
		}
		
	}
	
	// usuniêcie starej populacji
	for (int i = 0; i < populationQuantity; i++)
		delete population[i];

	population = newPopulation;

	return newPopulation;
}

void CGAOptimizer::showBestInPopulation() {

	int m = population[0]->getFitness(clauses, problem);
	int actual = m;
	bool* best = population[0]->getGenotype();

	for (int i = 1; i < populationQuantity; i++) {
		actual = population[i]->getFitness(clauses, problem);
		if (actual > m) {
			best = population[i]->getGenotype();
			m = actual;
		}
	}

	std::cout << "Najlepsze rozwiazanie w populacji to: " << actual << " dla osobnika: ";
	for (int i = 0; i < PROBLEMSIZE; i++)
		std::cout << best[i] ? 1 : 0;

	std::cout << std::endl;
	best = NULL;
}