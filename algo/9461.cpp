#include<iostream>

using  namespace std;


int main(){
    
    int n;
    
    cin>>n;
    
    unsigned long long pado[101];
    pado[0] = 0; pado[1] = 1; pado[2] = 1;
    
    for(int i=3;i<=100;i++) pado[i] = pado[i-3] + pado[i-2];
    //for(int i=1;i<=100;i++) cout<<pado[i]<<"\n";
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        cout<<pado[t]<<"\n";
    }
    
    return 0;
}
