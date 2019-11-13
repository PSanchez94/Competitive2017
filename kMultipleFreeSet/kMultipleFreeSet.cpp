// Submission Link: https://codeforces.com/contest/274/submission/17477423

#include <iostream>
#include <algorithm>
#include <vector>

bool VectorSort(int i, int j) { return i > j; }

int main() {
    
    // Input
    int n, k;
    scanf("%id",&n); scanf("%id",&k);
    double a[n];
    for (int i=0;i<=n-1;i++){
        scanf("%lfd",&a[i]);
    }
    
    // Binary search:
    // Run through array
    // Is half, it, or double in the set? If not, then add
    std::sort(a, a+n);
    std::vector<double> set;
    for (int i=0;i<=n-1;i++){
        if ( !((std::binary_search(set.begin(), set.end(), a[i]/k)) || (std::binary_search(set.begin(), set.end(), a[i])) || (std::binary_search(set.begin(), set.end(), a[i]*k))) )
            set.push_back(a[i]);
    }
    printf("%lu",set.size());
}