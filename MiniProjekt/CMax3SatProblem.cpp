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

	// odczytujemy dane
	int i = 0;
	while (i < amountOfClauses) {
		// pobieramy dane
		std::getline(file, line);

		// splitujemy po spacji
		std::stringstream streamData(line);
		while (std::getline(streamData, val, separator)) 
			outputArray.push_back(val);
		
		// nowa klauzla wrzucana do wektora
		Clause * read = new Clause(
			stoi(outputArray[1]),
			stoi(outputArray[3]),
			stoi(outputArray[5])
		);

		clauses.push_back(read);
		outputArray.clear();
		i++;
	}

	// zamykamy plik i sprz¹tamy
	outputArray.clear();
	file.close();

	return clauses;
}


int CMax3SatProblem::compute(bool* solution, int amountOfClauses, std::vector<Clause*>& clauzles) {
	int counter = 0;
	for (int i = 0; i < amountOfClauses; i++) {

		int nr = clauzles.at(i)->getSt();

		if (nr >= 0 && solution[nr]) {
			counter++;
			continue;
		}
		else {
			if (nr < 0 && !solution[std::abs(nr)]) {
				counter++;
				continue;
			}
		}

		int nr2 = clauzles.at(i)->getNd();

		if (nr2 >= 0 && solution[nr2]) {
			counter++;
			continue;
		}
		else {
			if (nr2 < 0 && !solution[std::abs(nr2)]) {
				counter++;
				continue;
			}
		}

		int nr3 = clauzles.at(i)->getRd();

		if (nr3 >= 0 && solution[nr3])
			counter++;
		else {
			if (nr3 < 0 && !solution[std::abs(nr3)])
				counter++;
		}
	}

	return counter;
}