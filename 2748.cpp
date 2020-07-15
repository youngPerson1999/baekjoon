#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    int n;
    long long fibo[91];

    scanf("%d",&n);

     if(n==0){
        cout<<"0";
        return 0;
    }
    else if(n==1||n==2){
        cout<<"1";
        return 0;
    }

    fibo[0] = 0;
    fibo[1] = 1;
    
    for(int i=2;i<=n;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }     

    printf("%lld",fibo[n]); 

    return 0;
}
