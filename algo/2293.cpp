#include <iostream>
#include<algorithm>

using namespace std;

int main(){
	
	int n,k,i,j;
	cin>>n>>k;
	
	int *coin = new int[n];
	int *dp = new int[k+1];
	
	fill(dp,dp+k+1,0);
	dp[0] = 1;
	for(i=0;i<n;i++) cin>>coin[i];
	
	for(i=0;i<n;i++){
	    if(coin[i]>k) continue;
	    dp[coin[i]] += 1;
	    for(j= coin[i]+1;j<=k;j++){
	        dp[j] += dp[j-coin[i]];
	    }
	}
	
	cout<<dp[k];
	
	return 0;
}
