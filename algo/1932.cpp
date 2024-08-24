#include<iostream>

using namespace std;

int main(){
    
    int n,i;
    cin>>n;
    
    int **trian = new int*[n];
    
    for(i=0;i<n;i++){
        trian[i] = new int[i+1];
        for(int j=0;j<=i;j++){
            int k;
            cin>>k;
            if(i==0) {
                trian[i][j] = k;
                break;
            }
            if(j==0) trian[i][j] = trian[i-1][j] + k;
            else if(j==i) trian[i][j] = trian[i-1][j-1] + k;
            else trian[i][j] = trian[i-1][j]<trian[i-1][j-1]?trian[i-1][j-1]+k:trian[i-1][j]+k;
        }
    }
    int max = 0;
    for(i=0;i<n;i++) if(trian[n-1][i]>max) max = trian[n-1][i];
    
    cout<<max;
    
    return 0;
}
