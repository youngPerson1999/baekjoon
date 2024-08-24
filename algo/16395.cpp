#include <iostream>

using namespace std;

int main()
{
    int n,k;
    
    cin>>n>>k;
    
    int **pascal = new int*[n+1];
    if(n==1||n==2){
        cout<<1;
        return 0;
    }
    pascal[1] = new int[2];
    pascal[2] = new int[3];
    pascal[1][1] = 1;
    pascal[2][1] = 1;   pascal[2][2] = 1;
    for(int i=3;i<=n;i++){
        pascal[i] = new int[i+1];
        pascal[i][1] = 1;
        pascal[i][i] = 1;
        for(int j=1;j<i;j++){
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
        }
    }
    cout<<pascal[n][k];
    return 0;
}
