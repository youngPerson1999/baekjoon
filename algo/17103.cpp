#include <iostream>

using namespace std;

bool isPrime(int n) { 
    if (n < 2) return false; 
    for (int i = 2; i * i <= n; i++) { 
        if (n % i == 0) return false; 
    } 
    return true; 
}

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    bool prime[1000001];
    for(int i=1;i<=1000000;i++) prime[i] = isPrime(i);
    
    int t,n,gp;
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>n;
        gp=0;
        if(n>=3&&n<=6) {
            cout<<1<<"\n";    continue;
        }
        for(int j=2;j<=n/2;j++){
            if(prime[j]&&prime[n-j]) gp++;
        }
        cout<<gp<<"\n";
    }
    
    return 0;
}
