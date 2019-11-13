// Submission Link: https://codeforces.com/contest/546/submission/16981697

#include <iostream>

int main() {
    int ks,ns,ws;
    std::cin >> ks >> ns >> ws;
    
    /*
    double k = atoi(ks.c_str());
    double n = atoi(ns.c_str());
    double w = atoi(ws.c_str());
    */

    if ((ws/2.0)*(1+ws)*ks >= ns) {
        int Answer = ((ws/2.0)*(1+ws))*ks - ns;
        std::cout << Answer << std::endl;
    }
    else {
        std::cout << 0 << std::endl;
    }
    return 0;
}