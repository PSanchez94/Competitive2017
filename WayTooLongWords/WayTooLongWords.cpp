// Submission Link: https://codeforces.com/contest/71/submission/25807458

#include <iostream>
#include <string>
#include <vector>
 
int main(int argc, const char * argv[]) {
    
    int Lines;
    std::cin >> Lines;
    std::vector<std::string> LongWords {};
 
    for(int i = 0; i < Lines; ++i) {
        std::string Aux;
        std::cin >> Aux;
        LongWords.push_back(Aux);
    }
 
    for(int i = 0; i < Lines; ++i) {
        if ( LongWords[i].length() > 10) {
            std::string LongerW = LongWords[i];
            std::string ShorterW;
            std::string Size = std::to_string(LongWords[i].size()-2);
 
            ShorterW.push_back(LongWords[i].front());
            ShorterW.append(Size);
            ShorterW.push_back(LongWords[i].back());
            
            std::cout << ShorterW << std::endl;
            
        }
        else {
            std::cout << LongWords[i] << std::endl;
        }
    }
    
    return 0;
}