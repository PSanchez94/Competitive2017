// Sumbission Link: https://codeforces.com/contest/230/submission/26759485

#include <iostream>
#include <math.h>
#include <vector>

int main () {
    
    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    long long int N; std::cin >> N;
    std::vector<long long int> Candidates;
    
    long long int Aux=0;
    for (long long int i=0;i<N;++i) {
        std::cin >> Aux;
        Candidates.push_back(Aux);
    }
    
    std::vector<bool> Primes;
    Primes.push_back(false); Primes.push_back(false);
    for (long long int i=2;i<1000001;++i) {
        Primes.push_back(true);
    }
    
    for (long long int i=2;i<1000001;++i) {
        if (Primes[i]) {
            for (long long int j=i;(j*i)<1000001;++j) {
                Primes[(j*i)]=false;
            }
        }
    }
    
    Aux=0;
    for (long long int i=0;i<N;++i) {
        if ((ceil(sqrt(Candidates[i])))==(floor(sqrt(Candidates[i])))) {
            Aux = sqrt(Candidates[i]);
            if (Primes[Aux]) {
                std::cout << "YES" << std::endl;
            }
            else {
                std::cout << "NO" << std::endl;
            }
        }
        else {
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
    
}