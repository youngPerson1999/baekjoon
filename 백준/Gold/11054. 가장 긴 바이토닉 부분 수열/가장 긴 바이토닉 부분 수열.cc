/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11054                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11054                          #+#        #+#      #+#    */
/*   Solved: 2024/09/28 16:39:10 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int n;
vector<int> s;

vector<int> dp_sol(){
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            if (s[j] < s[i])
                dp[i] = max(dp[i], dp[j] + 1);
    return dp;
}

int main()
{
    cin >> n;

    vector<int> sol, sol_down;
    s.resize(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sol = dp_sol();
    reverse(s.begin(), s.end());
    sol_down = dp_sol();
    // for (int i = 0; i < n; i++)
    //     cout << sol[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i < n; i++)
    //     cout << sol_down[i] << ' ';
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = sol[i] + sol_down[n - i - 1] - 1;
        max = sum > max ? sum : max;
    }
    cout << max << '\n';
    return 0;
}