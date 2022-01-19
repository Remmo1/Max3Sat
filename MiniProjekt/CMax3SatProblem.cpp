#include "CMax3SatProblem.h"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


std::vector<Clause*> CMax3SatProblem::load(int amountOfClauses, std::string filename) {

	// otwieranie pliku
	std::ifstream file;
	file.open(filename);
	if (!file.good())
		return std::vector<Clause*>();

	// wektor klauzl
	std::vector<Clause*> clauses;

	// potrzebne do splitowania
	std::string line;
	const char separator = ' ';
	std::vector<std::string> outputArray;
	std::string val;

	// sta³a potrzebna do nieprzyjemnego -0
	int MINUSZERO = 123456;

	// odczytujemy dane
	int i = 0;
	while (i < amountOfClauses) {
		// pobieramy dane
		std::getline(file, line);

		// splitujemy po spacji
		std::stringstream streamData(line);
		while (std::getline(streamData, val, separator)) 
			outputArray.push_back(val);
		
		// sprawdzenie nieprzyjemnego przypadku -0
		int st = outputArray[1] == "-0" ? MINUSZERO : stoi(outputArray[1]);
		int nd = outputArray[3] == "-0" ? MINUSZERO : stoi(outputArray[3]);
		int rd = outputArray[5] == "-0" ? MINUSZERO : stoi(outputArray[5]);

		// nowa klauzla wrzucana do wektora
		Clause * read = new Clause(st, nd, rd);

		clauses.push_back(read);
		outputArray.clear();
		i++;
	}

	// zamykamy plik i sprz¹tamy
	outputArray.clear();
	file.close();

	return clauses;
}


int CMax3SatProblem::compute(bool* solution, int amountOfClauses, std::vector<Clause*>& clauses) {

	// licznik rozwi¹zania
	int counter = 0;

	// sta³a potrzebna dla -0
	int MINUSZERO = 123456;

	for (int i = 0; i < amountOfClauses; i++) {

		/*
		* metoda dzia³a tak, weŸmy np. klauzlê (0, -1, 2) oraz rozwi¹zanie 000
		* dla 0 mamy rozwi¹zanie[0] = 0 zatem false, czyli musimy sprawdzaæ dalej
		* dla -1 mamy rozwi¹zanie[1] = 0 czyli true, poniewa¿ dla 1 -> flase <=> -1 -> true
		* nie musimy ju¿ sprawdzaæ ostatniego trzeciego elementu bo klauzula jest spe³niona, wiêc 
		* przechodzimy dalej u¿ywaj¹c continue
		*/

		// wartoœæ pierwsza w klauzuli
		int nr = clauses.at(i)->getSt();

		if (nr == MINUSZERO && solution[0] == 0) {
			counter++;
			continue;
		}
		else if (nr >= 0 && nr != MINUSZERO && solution[nr]) {
			counter++;
			continue;
		}
		else {
			if (nr < 0 && !solution[std::abs(nr)]) {
				counter++;
				continue;
			}
		}


		// wartoœæ druga w klauzuli
		int nr2 = clauses.at(i)->getNd();

		if (nr2 == MINUSZERO && solution[0] == 0) {
			counter++;
			continue;
		}
		else if (nr2 >= 0 && nr2 != MINUSZERO && solution[nr2]) {
			counter++;
			continue;
		}
		else {
			if (nr2 < 0 && !solution[std::abs(nr2)]) {
				counter++;
				continue;
			}
		}


		// wartoœæ trzecia w klauzuli
		int nr3 = clauses.at(i)->getRd();

		if (nr3 == MINUSZERO && solution[0] == 0)
			counter++;
		else if (nr3 >= 0 && nr3 != MINUSZERO && solution[nr3]) 
			counter++;
		else {
			if (nr3 < 0 && !solution[std::abs(nr3)])
				counter++;
		}
	}

	return counter;
}