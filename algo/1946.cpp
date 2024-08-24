#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stdio.h>

using namespace std;

int Max_Employ(int n);

int main()
{
    int T,N;
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d",&N);
        printf("%d\n",Max_Employ(N));
        getchar();
    }
    
    return 0;
}
int Max_Employ(int n){
    
    vector<pair<int,int> > employee;
    
    for(int i=0;i<n;i++){
        int rank_1, rank_2;
        scanf("%d %d",&rank_1, &rank_2);
        employee.push_back(make_pair(rank_1,rank_2));
    }
    sort(employee.begin(),employee.end());
    int min = n+1; int sol = 0;
    for(int i=0;i<n;i++){
        if(min>employee[i].second){
            sol++;
            min = employee[i].second;
        }
    }
    return sol;
}
