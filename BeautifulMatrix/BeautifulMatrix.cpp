// Submission Link: https://codeforces.com/contest/263/submission/25810102

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
 
int main() {
    
    std::string Input;
    std::vector<std::string> Aux;
    int Row = 0;
    int Column = 0;
    int Pasos = 0;
    
    for (int i = 0; i < 5; ++i) {
        std::getline(std::cin,Input);
        Aux.push_back(Input);
    }
    
    for (int i = 0; i < 5; ++i) {
        if ( Aux[i].find("1") != std::string::npos ) {
            Column = i;
            Row = Aux[i].find("1")/2;
        }
    }
    
    Pasos = std::abs(Column - 2) + std::abs(Row -2);
    
    std::cout << Pasos;
    
}