#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){

    int n,time = 0;

    cin>>n;
    getchar();

    int *num = new int[n];

    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    sort(num, num + n);

    int weight = n;

    for(int i=0;i<n;i++,weight--){
        time += weight*num[i];
    }

    cout<<time;

    return 0;
}
