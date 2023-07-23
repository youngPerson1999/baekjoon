#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n;

int calSol(vector<int> num, vector<vector<int> > dp){
    //최솟값은 1번 원소부터
    int max_n = num[0];
    dp[0][0] = dp[1][0] = num[0];
    for (int i = 1; i < n; i++)
    {
        //기존 연속합을 구하는 로직
        dp[0][i] = max(dp[0][i], dp[0][i - 1] + num[i]);
        if (i != 1)
        {
            //[0][i-2] -> 건너뛴다는 의미
            dp[1][i] = max(dp[0][i - 2], dp[1][i - 1]) + num[i];
        }
        max_n = max(max_n, max(dp[0][i], dp[1][i]));
    }
    return max_n;
}

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<int> num(n, 0);

    int max_n = -1001;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        max_n = max(max_n, num[i]);
    }
    vector<vector<int> > dp(2, num);
    
    // 최댓값 <= 0이면 하나만 가지고 있는게 최대, 1개일때는 안해도 됨.
    if (max_n > 0 && n > 1)
        max_n = calSol(num, dp);
    cout << max_n << "\n";
    return 0;
}