#include<iostream>

using namespace std;


int main(){
    
    int n;
    
    cin>>n;
    
    unsigned long long f[117];
    f[1]=1; f[2]=1; f[3]=1;
    if(n<=3){
        cout<<f[n];
        return 0;
    }
    for(int i=4;i<=n;i++){
        f[i] = f[i-1] + f[i-3];
    }
    cout<<f[n];
    
    return 0;
}
