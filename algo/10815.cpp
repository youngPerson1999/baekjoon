#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int *tree;

void bsearch(int, int);

int main(){

    int n;

    cin>>n;
    getchar();

    tree = new int[n];

    for(int i=0;i<n;i++){
        cin>>tree[i];
    }

    sort(tree,tree+n);

    int m;

    cin>>m;
    getchar();

    int *key = new int[m];

    for(int i=0;i<m;i++){
        cin>>key[i];
    }
    for(int i=0;i<m;i++){
        bsearch(key[i],n);
    }
    return 0;
}
void bsearch( int key, int length){

    int low = 0;
    int high = length;

    while(low<=high){

        int mid = low + (high-low)/2;

        if(tree[mid]==key){
            cout<<"1 ";
            return;
        }
        else if(tree[mid]<key) low = mid + 1;
        else high = mid -1;
    }

    cout<<"0 ";
}