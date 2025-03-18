/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 5557                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/5557                           #+#        #+#      #+#    */
/*   Solved: 2025/03/18 16:45:05 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int n;
long long cnt = 0;
vector<int> num;
vector<vector<long long> > sol;

long long sol_cnt() {
    int right = num[n - 1];
    // init
    if(num[0] + num[1] <= 20)
        sol[1][num[0] + num[1]] += 1;
    if(num[0] - num[1] >= 0)
        sol[1][num[0] - num[1]] += 1;
    for (int i = 2; i < n - 1; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            long long prev_cnt = sol[i - 1][j];
            if (prev_cnt == 0)
                continue;
            if (j + num[i] <= 20)
                sol[i][j + num[i]] += prev_cnt;
            if (j - num[i] >= 0)
                sol[i][j - num[i]] += prev_cnt;
        }
    }
    return sol[n - 2][right];
}

int main()
{
    cin >> n;
    num.resize(n);
    sol.resize(n - 1, vector<long long>(21, 0));
    for (int i = 0; i < n; i++)
        cin >> num[i];
    cout << sol_cnt() << '\n';

    return 0;
}