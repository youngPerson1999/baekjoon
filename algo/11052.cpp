#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    
    cin>>n;
    
    vector<int> P(n+1);
    vector<vector<int> > sol(n+1,vector<int>(n+1,0));
    //sol[i][j]: i means value of card, j means the number of cards i took in
    
    for(int i=1;i<=n;i++)
        cin>>P[i];
    
    for(int i=0;i<=n;i++) sol[1][i] = P[1]*i;
    
    for(int i=2;i<=n;i++){
        for(int j=0;j<=n;j++){
            int tmp_max = sol[i-1][j];
            for(int k=0;k<=j;k+=i){
                tmp_max = max(tmp_max,sol[i-1][j-k]+(k/i)*P[i]);
            }
            sol[i][j] = tmp_max;
            
        }
    }
    
    cout<<sol[n][n];
    
    return 0;
}
