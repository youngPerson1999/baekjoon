/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 13549                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/13549                          #+#        #+#      #+#    */
/*   Solved: 2024/09/11 20:33:49 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,k;
queue<pair<int, int> > q;
vector<int> hide(1000001, 1000001);

int cal_time()
{
    int rst_time = 0;
    q.push({n, rst_time});
    hide[n] = 0;
    while (!q.empty())
    {
        int cur = q.front().first;
        int cur_time = q.front().second;
        q.pop();
        if (cur > 0 && cur_time + 1 < hide[cur - 1])
        {
            hide[cur - 1] = cur_time + 1;
            q.push({cur - 1, cur_time + 1});
        }
        if (cur <= 100000 && cur_time + 1 < hide[cur + 1])
        {
            hide[cur + 1] = cur_time + 1;
            q.push({cur + 1, cur_time + 1});
        }
        if (cur * 2 <= 100000 && cur_time < hide[cur * 2])
        {
            hide[cur * 2] = cur_time;
            q.push({cur *2, cur_time});
        }
    }
    return hide[k];
}

int main()
{
    cin >> n >> k;
    cout << cal_time() << '\n';
    return 0;
}