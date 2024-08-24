#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    
    cin>>n;
    
    int *stair = new int[n];
    int **dp = new int*[n];
    
    for(int i=0;i<n;i++){
        cin>>stair[i];
        dp[i] = new int[3];
        dp[i][0] = 0; dp[i][1] = 0; dp[i][2] = 0;
        //dp[][0] -> oo, [1] -> ox, [2] -> xo
    }
    
    if(n<3){
        int sol = 0;
        for(int i=0;i<n;i++) sol += stair[i];
        cout<<sol;
        return 0;
    }
    dp[0][0] = stair[0];
    dp[0][1] = stair[0];
    dp[0][2] = 0;
    dp[1][0] = dp[0][0] + stair[1];
    dp[1][1] = dp[0][0];
    dp[1][2] += stair[1];
    
    for(int i=2;i<n;i++){
        dp[i][0] = dp[i-1][2] + stair[i];
        dp[i][1] = max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = dp[i-1][1] + stair[i];
        //cout<<i<<" 0 : "<<dp[i][0]<<", 1 : "<<dp[i][1]<<", 2 : "<<dp[i][2]<<endl;
    }
    
    cout<<max(dp[n-1][0],dp[n-1][2]);
    
    return 0;
}
