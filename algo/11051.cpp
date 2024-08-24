#include <iostream>
#include <cstring>

using namespace std;

int bino[1001][1001];

int cal_bino(int n, int k);

int main()
{
    int n,k;
    
    cin>>n>>k;
    
    memset(bino,-1,sizeof(bino));
    
    bino[1][0]=1;  bino[1][1]=1;
    
    int sol = cal_bino(n,k)%10007;
    
    cout<<sol;
    
    return 0;
}
int cal_bino(int n, int k){
    if(n==k||n==0||k==0) return 1;
    if(bino[n][k]!=-1) return bino[n][k];
    return bino[n][k] = cal_bino(n-1,k)%10007 + cal_bino(n-1,k-1)%10007;
}
