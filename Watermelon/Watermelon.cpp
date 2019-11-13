// Submission Link: https://codeforces.com/contest/4/submission/25802993

#include <iostream>
 
int main() {
    
    int Kilos;
    
    std::cin >> Kilos;
    
    if ( ( Kilos%2 ) == 0 && Kilos != 2 && Kilos > 0) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }
}