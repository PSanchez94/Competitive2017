// Submission Link: https://codeforces.com/contest/237/submission/26947425

#include <iostream>
#include <vector>

int main () {
    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    
    std::vector<bool> Primes;
    std::vector<long long int> HowManyP;
    Primes.push_back(false); Primes.push_back(false);
    HowManyP.push_back(0); HowManyP.push_back(0);
    
    for (long long int i=2;i<1000010;++i) {
        Primes.push_back(true);
        HowManyP.push_back(0);
    }
    
    for (long long int i=2;i<1000010;++i) {
        if (Primes[i]) {
            for (long long int j=i;(j*i)<1000010;++j) {
                Primes[(j*i)]=false;
            }
            HowManyP[i] = HowManyP[i-1] + 1;
        }
        else {
            HowManyP[i] = HowManyP[i-1];
        }
    }

    long long int A,B,K;
    std::cin >> A;
    std::cin >> B;
    std::cin >> K;

    long long int mid;
    long long int Gum = 1;
    long long int FinalL = -1;
    long long int Binary = ((B-A)+1);


    while (Gum <= Binary) {
        mid = (Gum+Binary)/2;
        for (long long int i=A;i<=B-mid+1;++i) {
            if (HowManyP[i+mid-1] - HowManyP[i-1] < K) {
                Gum=mid+1; break;
            }
            else if (i==(B-mid+1)) {
                Binary=mid-1;
                FinalL=mid;
            }
        }
    }

    std::cout << FinalL << std::endl;

    return 0;
}