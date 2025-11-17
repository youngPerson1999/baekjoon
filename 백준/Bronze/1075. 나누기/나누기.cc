#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, f, count = 0;
    cin>>n>>f;
    int nn = 0, n_copy=n, first;
    n = n/100*100;

    for (int i = 0; i < 100; i++)
    {
        if(n % f == 0) break;
        n++;
        count++;
    }
    if(count < 10) cout<<'0';
    cout<<count;
    return 0;
}