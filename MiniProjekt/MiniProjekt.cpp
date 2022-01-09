﻿#include <iostream>
#include <vector>
#include "CMax3SatProblem.h"
#include "CGAIndividual.h"

int main()
{
    CMax3SatProblem problem = CMax3SatProblem();

    std::vector<Clause*> clauzules = problem.load(213, "m3s_50_14.txt");
    
    int a = problem.compute(
        "111111111111111111111111111111111111111111111111111",
        213,
        clauzules
    );
    std::cout << a << std::endl;

    int b = problem.compute(
        "000000000000000000000000000000000000000000000000000",
        213,
        clauzules
    );
    std::cout << b << std::endl;

    
    

    CGAIndividual* r1 = new CGAIndividual(true);
    CGAIndividual* r2 = new CGAIndividual(false);

    r1->showGenotype();
    r2->showGenotype();

    std::cout << r1->getFitness(problem) << std::endl;
    std::cout << r2->getFitness(problem) << std::endl;

    bool** children = r1->crossover(*r2);

    CGAIndividual* c1 = new CGAIndividual(children[0]);
    CGAIndividual* c2 = new CGAIndividual(children[1]);

    c1->showGenotype();
    c2->showGenotype();

    c1->mutation(30);
    c2->mutation(70);

    c1->showGenotype();
    c2->showGenotype();
  
   

 
}