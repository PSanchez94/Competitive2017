// Submission Link: https://codeforces.com/contest/158/submission/16981735

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
 
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
 
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
 
int main(int argc, const char * argv[]) {
    
    std::string NKLine, ScoreLine;
    std::vector<std::string> NKString, ScoreString;
    std::getline(std::cin, NKLine); std::getline(std::cin, ScoreLine);
    
    split(NKLine, ' ', NKString);
    split(ScoreLine, ' ', ScoreString);
    
    std::vector<int> NKVector;
    for (int i=0; i<= 1; i++){
        float num = atoi(NKString.at(i).c_str());
        NKVector.push_back(num);
    }
    
    std::vector<int> ScoreVector;
    for (int i=0; i<= NKVector[0] - 1 ; i++){
        float num = atoi(ScoreString.at(i).c_str());
        ScoreVector.push_back(num);
    }
    
    std::sort (ScoreVector.begin(), ScoreVector.end());
    
    int k = ScoreVector[NKVector[0] - NKVector[1]];
    
    std::vector<int>::iterator low;
    low = std::lower_bound (ScoreVector.begin(), ScoreVector.end(), k);
    
    float IndexWinner = (ScoreVector.begin() - low);
    float Winners = (ScoreVector.end() - low);
    
    for (int i=IndexWinner; i<= ScoreVector.size()-1; i++){
        if (ScoreVector[i]<=0){
            Winners = Winners - 1;
        }
    }
 
    
    std::cout << Winners;
    
    return 0;
}