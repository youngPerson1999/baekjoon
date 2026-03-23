#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> dp;
vector<int> t;
vector<int> p;


int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    dp.resize(n + 51);
    t.resize(n + 51);
    p.resize(n + 51);

    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        if (dp[i] < dp[i - 1])
            dp[i] = dp[i - 1];
        dp[i + t[i] - 1] = max(dp[i + t[i] - 1], dp[i - 1] + p[i]);
    }

    cout << dp[n] <<'\n';
    return 0;
}