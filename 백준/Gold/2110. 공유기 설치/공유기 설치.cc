/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2110                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2110                           #+#        #+#      #+#    */
/*   Solved: 2024/11/12 22:24:51 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c, dist;
vector<int> x;

// bool is_possible(int d)
// {
//     vector<int> dists;
//     int left = 1, right = n - 1;
//     dists.push_back(0);
//     while(left <= right)
//     {
//         int dists_idx = dists[dists.size() - 1];
//         int mid = (left + right + 1) / 2;
//         int mid_dist = x[mid] - x[dists_idx];
//         if (mid_dist == d || mid - dists_idx == 1)
//         {
//             dists.push_back(mid);
//             left = mid + 1;
//             right = n - 1;
//         }
//         else if(mid_dist < d)
//         {
//             left = mid + 1;
//         }
//         else
//         {
//             right = mid - 1;
//         }
//         if (dists.size() == c)
//             break;
//     }
//     return dists.size() == c;
// }


bool is_possible(int d)
{
    int tmp_c = c - 1, tmp_idx = 0;
    int left = 0, right = n - 1;
    for (int i = 1; i < n; i++)
    {
        int t_dist = x[i] - x[tmp_idx];
        if(t_dist >= d)
        {
            tmp_c--;
            tmp_idx = i;
        }
        if (tmp_c == 0)
            break;
    }
    return tmp_c == 0;
}

void parametic_search()
{
    int left = 1, right = x[n - 1] - x[0];
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if(is_possible(mid))
        {
            left = mid + 1;
            dist = mid;
        }
        else
        {
            right = mid-1;
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> c;
    x.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    parametic_search();
    cout << dist << '\n';
    return 0;
}