#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> p(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<int> dp(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        //initialize dp with the price of the whole stick
        dp[i] = p[i];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }
    }

    cout<< dp[n] << '\n';
    return 0;
}