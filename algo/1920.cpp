#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

void bsearch(int*,int,int);

int main(){

    int n,i,m,tmp;

    cin>>n;
    getchar();

    int* num = new int[n];

    for(i=0;i<n;i++){
        cin>>num[i];
    }
    getchar();

    sort(num,num+n);
   
    cin>>m;

    int* M = new int[m];
    getchar();

    for(i=0;i<m;i++){
        cin>>M[i];
    }
    for(i=0;i<m;i++){
        bsearch(num,M[i],n-1);
    }
    
   
    return 0;
}
void bsearch(int*num, int key, int length){

    int low = 0;
    int high = length;

    while(low<=high){

        int mid = low + (high-low)/2;

        if(num[mid]==key){
            cout<<"1\n";
            return;
        }
        else if(num[mid]<key) low = mid + 1;
        else high = mid -1;
    }

    cout<<"0\n";
}