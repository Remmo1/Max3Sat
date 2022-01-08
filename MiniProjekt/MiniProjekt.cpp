#include <iostream>
#include <vector>
#include "CMax3SatProblem.h"

int main()
{
    CMax3SatProblem c1;
    std::vector<Clause*> clauses = c1.load(213, "m3s_50_0.txt");

    for (int i = 0; i < 213; i++)
        clauses.at(i)->show();


    int result = c1.compute(
        "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", 
        213, 
        clauses
    );

    int result2 = c1.compute(
        "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        213,
        clauses
    );

    int result3 = c1.compute(
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        213,
        clauses
    );
    
    std::cout << "solution for 010101... : " << result << std::endl;
    std::cout << "solution for 000000... : " << result2 << std::endl;
    std::cout << "solution for 111111... : " << result3 << std::endl;
}