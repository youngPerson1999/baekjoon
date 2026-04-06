#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> T(n + 1);
    vector<int> P(n + 1);
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> T[i] >> P[i];

    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i]);
        if(i + T[i] - 1 <= n)
            dp[i + T[i] - 1] = max(dp[i - 1] + P[i], dp[i + T[i] - 1]);
    }

    cout << dp[n] << '\n';
    return 0;
}