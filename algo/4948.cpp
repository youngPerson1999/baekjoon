#include<iostream>

using namespace std;
void printPrime(int n){
    int *num = new int[n*2+1];
    int cnt = 0;
    for(int i=2;i<=2*n;i++){
        num[i]=i;
    }
    for(int i=2;i<=2*n;i++){
        if(num[i]==0) continue;
        for(int j=2*i;j<=2*n;j+=i) num[j] = 0;
    }
    for(int i=n+1;i<=2*n;i++) if(num[i] != 0) cnt++;
    cout<<cnt<<"\n";
}
int main(){
    
    int n;
    while(1){
        cin>>n;
        if(n==0) break;
        printPrime(n);
        cin.clear();
        
    }
}
