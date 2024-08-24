#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    int n,in;

    scanf("%d",&n);

    int *num = new int[10001];

    for(int i=1;i<=10000;i++)
        num[i] = 0;

    for(int i=0;i<n;i++){
        scanf("%d",&in);
        num[in]++;
    }

    for(int i=1;i<10001;i++){
        if(num[i]==0)   continue;
        for(int j=0;j<num[i];j++)    
            printf("%d\n",i);
    }

    return 0;
}