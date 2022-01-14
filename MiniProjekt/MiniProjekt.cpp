#include <iostream>
#include <vector>
#include "CMax3SatProblem.h"
#include "CGAOptimizer.h"
#include "CGAIndividual.h"

int main()
{
    // tworzymy problem
    CMax3SatProblem problem = CMax3SatProblem();

    // tworzymy optymalizator
    CGAOptimizer * op1 = new CGAOptimizer(10, 30, 30, problem);
 
    // wczytujemy dane w metodzie initialize, jeśli się nie da to wychodzimy
    if (op1->initialize("m3s_50_14.txt")) {

        std::cout << "Populacja przed: " << std::endl;
        op1->showPopulation();
        op1->showBestInPopulation();

        std::cout << std::endl;

        op1->runIteration();
        std::cout << "Populacja po 1 iteracji: " << std::endl;
        op1->showPopulation();
        op1->showBestInPopulation();

        std::cout << std::endl;
        

        op1->runIteration();
        std::cout << "Populacja po 2 iteracji: " << std::endl;
        op1->showPopulation();
        op1->showBestInPopulation();
        
    }
    else {
        std::cout << "Nie udalo sie otworzyc pliku z danymi, sprawdz czy nazwa jest poprawna! Program zostanie zakonczony" << std::endl;
    }

    delete op1;
}