/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9251                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9251                           #+#        #+#      #+#    */
/*   Solved: 2024/09/18 17:08:36 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s1, s2;
int dp_num = 0;
vector<vector<int> > dp(1001, vector<int>(1001));

int max(int a, int b)
{
    return a > b ? a : b;
}
void sol()
{
    int s1_size = s1.length(), s2_size = s2.length();
    for (int i = 1; i <= s1_size; i++)
        for (int j = 1; j <= s2_size; j++)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                dp_num = max(dp[i][j], dp_num);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
    }
    cout << dp_num << '\n';
}

int main()
{
    cin >> s1 >> s2;
    sol();
    return 0;
}