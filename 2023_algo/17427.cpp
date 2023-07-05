#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int n;

    cin>>n;

    long long result = 0;

    for(int i = 1; i <= n; i++)
        result += i * (n / i);
    
    cout<<result<<"\n";

    return 0;
}