#include<iostream>

using namespace std;

int main(){

    int n;

    cin>>n;

    int *num = new int[n+1];
    num[1] = 0;
    for(int i=2;i<=n;i++){
        num[i] = num[i-1]+1;
        if(i%2==0) num[i] = num[i] <  num[i/2]+1 ? num[i] : num[i/2]+1;
        if(i%3==0) num[i] = num[i] <  num[i/3]+1 ? num[i] : num[i/3]+1;
    }
    cout<<num[n];
    return 0;
}
