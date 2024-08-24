#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){

    int N;
    
    scanf("%d",&N);

    int *A = new int[N];

    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);

    sort(A,A+N);

    for(int i=0;i<N;i++)
        printf("%d\n",A[i]);

    delete[] A;

    return 0;
}
