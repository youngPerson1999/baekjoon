#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int>per;
int n,m;
bool *check;
void permutation(int depth, int l[], int arr[]){
    if(depth==m){
        for(int i=0;i<m;i++) cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(!check[i]){
            check[i] = true;
            arr[depth]=l[i];
            permutation(depth+1,l,arr);
            check[i] = false;
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;
    int list[n];
    int arr[m];
    check = new bool[n];
    for(int i=0;i<n;i++){
        cin>>list[i];
        check[i] = false;
    }
    sort(list,list+n);
    permutation(0,list,arr);
    return 0;
}
