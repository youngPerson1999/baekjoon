#include<iostream>

using namespace std;

int main(){

    int n;

    cin>>n;

    if(n==1||n==2){
        cout<<"1";
        return 0;
    }

    long long num[91];

    num[1] = 1;
    num[2] = 1;

    for(int i=3;i<=n;i++){
        num[i] = num[i-1] + num[i-2];
    }

    cout<<num[n];

    return 0;
}
