/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14889                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14889                          #+#        #+#      #+#    */
/*   Solved: 2024/09/18 22:26:54 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > S;
vector<int> t1, t2;
int n, min_abil = 2000;

void cal_min_abil()
{
    int sum_1 = 0, sum_2 = 0, tmp;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            sum_1 += S[t1[i]][t1[j]];
            sum_2 += S[t2[i]][t2[j]];
        }
    }
    tmp = sum_1 > sum_2 ? sum_1 - sum_2 : sum_2 - sum_1;
    min_abil = min_abil > tmp ? tmp : min_abil;
}

void combination(int depth, int next)
{
    if(depth == n/2)
    {
        t2.resize(0);
        int t_i = 0;
        for (int i = 0; i < n; i++)
        {
            if (t_i < n/2&& t1[t_i] == i)
            {
                t_i++;
                continue;
            }
            t2.push_back(i);
        }
        cal_min_abil();
        return;
    }
    for (int i = next; i < n; i++)
    {
        t1[depth] = i;
        combination(depth + 1, i + 1);
    }
}

int main()
{
    cin >> n;
    S.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++ )
        for (int j = 0; j < n; j++)
            cin >> S[i][j];
    t1.resize(n / 2);
    combination(0, 0);
    cout << min_abil << '\n';
}