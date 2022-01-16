#include "CGAOptimizer.h"


CGAOptimizer::CGAOptimizer(
	int _populationQuantity, 
	int _probabilityCrossing, 
	int _probabilityMutation, 
	CMax3SatProblem _problem
) {
	populationQuantity = _populationQuantity;
	probabilityCrossing = _probabilityCrossing;
	probabilityMutation = _probabilityMutation;
	problem = _problem;
}

CGAOptimizer::~CGAOptimizer() {
	for (int i = 0; i < population.size(); i++) 
		delete population[i];
	
	if (!clauses.empty()) {
		for (int i = 0; i < AMOUNTOFCLAUSES; i++)
			delete clauses[i];
	}

	population.clear();
	clauses.clear();
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

CGAIndividual* CGAOptimizer::tournament(std::vector<CGAIndividual*> somePopulation) {
	// losowanie osobników do turnieju
	bool* isInTournament = new bool[populationQuantity];
	for (int j = 0; j < populationQuantity; j++)
		isInTournament[j] = false;

	std::vector<CGAIndividual*> areInTournament;
	int i = 0;
	CGAIndividual* actual = nullptr;

	while (i < TOURNAMENTSIZE) {
		// losujemy osobnika
		int index = std::rand() % populationQuantity;

		// sprawdzamy czy ju¿ jest w turnieju, jeœli nie ma dopisujemy go do listy uczestników
		if (!isInTournament[index]) {
			actual = somePopulation.at(index);
			isInTournament[index] = true;
			areInTournament.push_back(actual);
			i++;
		}
	}

	// szukamy zwyciêzcy
	CGAIndividual* winner = areInTournament[0];
	int actualResult = winner->getFitness(clauses, problem);

	for (int j = 1; j < TOURNAMENTSIZE; j++) {
		int act = areInTournament.at(j)->getFitness(clauses, problem);

		if (act > actualResult) {
			actualResult = act;
			winner = areInTournament.at(j);
		}
	}

	// sprz¹tamy
	delete[] isInTournament;
	areInTournament.clear();
	actual = NULL;

	// zwracamy zwyciêzcê
	return winner;
}

void CGAOptimizer::runIteration() {
	srand(time(NULL));

	std::vector<CGAIndividual*> newPopulation;

	CGAIndividual* father = nullptr;
	CGAIndividual* mother = nullptr;
	CGAIndividual* child1 = nullptr;
	CGAIndividual* child2 = nullptr;

	while (newPopulation.size() < population.size()) {

		// wybór ojca 
		father = tournament(population);

		// wybór matki
		mother = tournament(population);

		// zabezpieczenie przed wybraniem tego samego osobnika
		while (mother == father) 
			mother = tournament(population);

		// sprawdzenie czy krzy¿ujemy
		int probability = (std::rand() % 100) + 1;

		// krzy¿owanie genów jeœli wartoœæ mniejsza
		if (probability < probabilityCrossing) {
			bool** children = father->crossover(*mother);
			child1 = new CGAIndividual(children[0]);
			child2 = new CGAIndividual(children[1]);

			// ustawienie podwójnego wskaŸnika na NULL po pobraniu tablic
			children[0] = NULL;
			children[1] = NULL;
			delete[] children;
			children = NULL;

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