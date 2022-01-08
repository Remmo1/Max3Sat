#include "CMax3SatProblem.h"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


std::vector<Clause*> CMax3SatProblem::load(int n, std::string filename) {

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
	while (i < n) {
		// splitujemy
		std::getline(file, line);
		std::stringstream streamData(line);
		
		while (std::getline(streamData, val, separator)) {
			outputArray.push_back(val);
		}

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

	file.close();
	return clauses;
}


int CMax3SatProblem::compute(std::string solution, int amountOfClauzules, std::vector<Clause*>& clauzles) {
	int counter = 0;
	for (int i = 0; i < amountOfClauzules; i++) {

		int nr = clauzles.at(i)->getSt();
		nr += 50;

		if (solution[nr] == '1') {
			counter++;
			continue;
		}

		int nr2 = clauzles.at(i)->getNd();
		nr2 += 50;

		if (solution[nr2] == '1') {
			counter++;
			continue;
		}

		int nr3 = clauzles.at(i)->getRd();
		nr3 += 50;

		if (solution[nr3] == '1') {
			counter++;
			continue;
		}
	}

	return counter;
}