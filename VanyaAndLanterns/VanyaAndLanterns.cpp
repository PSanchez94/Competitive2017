// Submission Link: https://codeforces.com/contest/492/submission/17473669

#include <iostream>
#include <algorithm>
#include <iomanip>
 
int main() {
    
    // Input
    int n; double l;
    scanf("%id",&n); scanf("%lfd",&l);
    double a[n+1];
    a[0] = 0.0; a[n+1] = l;
    for (int i=1;i<=n;i++){
        scanf("%lfd",&a[i]);
    }
    
    // Difference Array
    double Dif[n];
    std::sort(a, a+(n+1));
    Dif[0] = ((a[1] - a[0])); Dif[n] = ((a[n+1] - a[n]));
    double aux = 0;
    for (int i=1;i<=n-1;i++){
        Dif[i] = ((a[i+1] - a[i])/2.0);
        if(Dif[i] > aux)
            aux = Dif[i];
    }
    
    // First and Last Values
    if(Dif[0] > aux)
        aux = Dif[0];
    if(Dif[n] > aux)
        aux = Dif[n];
 
    printf ("%.*f",9,aux);
}