/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9465                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9465                           #+#        #+#      #+#    */
/*   Solved: 2024/09/14 01:31:01 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int> > sticks;

int max_n(int a, int b)
{
    return a > b ? a : b;
}

int dp()
{
    vector<vector<int> > sol(2, vector<int>(n, 0));
    sol[0][0] = sticks[0][0];
    sol[1][0] = sticks[1][0];
    if (n > 1)
    {
        sol[0][1] = sol[1][0] + sticks[0][1];
        sol[1][1] = sol[0][0] + sticks[1][1];
        for (int i = 2; i < n; i++)
        {
            sol[0][i] = sticks[0][i] + max_n(sol[1][i - 1], sol[1][i - 2]);
            sol[1][i] = sticks[1][i] +  max_n(sol[0][i - 1], sol[0][i - 2]);
        }
    }
    return max_n(sol[0][n - 1], sol[1][n - 1]);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    sticks.resize(2);
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        sticks[0].resize(n);
        sticks[1].resize(n);
        for (int j = 0; j < n; j++)
            cin >> sticks[0][j];
        for (int j = 0; j < n; j++)
            cin >> sticks[1][j];
        cout << dp() << '\n';
    }

    return 0;
}