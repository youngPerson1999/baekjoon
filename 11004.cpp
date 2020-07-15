#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){

    int N,K;
    
    scanf("%d %d",&N,&K);

    int *A = new int[N];

    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);

    sort(A,A+N);

    printf("%d",A[K-1]);

    delete[] A;

    return 0;
}
