/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14500                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14500                          #+#        #+#      #+#    */
/*   Solved: 2024/09/06 17:59:43 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int n, m, max_sum = 0;
vector<vector<int> > map;

void cmp_max(int a)
{
    max_sum = a > max_sum ? a : max_sum;
}

void sum_type_t_j_l(int x, int y)
{
    int sum = 0;
    //세로
    if (x < n - 2)
    {
        sum = map[x][y] + map[x + 1][y] + map[x + 2][y];
        if (y > 0)
        {
            cmp_max(sum + map[x + 1][y - 1]);
            cmp_max(sum + map[x][y - 1]);
            cmp_max(sum + map[x + 2][y - 1]);
        }
        if (y < m - 1)
        {
            cmp_max(sum + map[x + 1][y + 1]);
            cmp_max(sum + map[x][y + 1]);
            cmp_max(sum + map[x + 2][y + 1]);
        }
    }
    //가로
    if(y < m - 2)
    {
        sum = map[x][y] + map[x][y + 1] + map[x][y + 2];
        if (x > 0)
        {
            cmp_max(sum + map[x - 1][y + 1]);
            cmp_max(sum + map[x - 1][y]);
            cmp_max(sum + map[x - 1][y + 2]);
        }
        if (x < n - 1)
        {
            cmp_max(sum + map[x + 1][y + 1]);
            cmp_max(sum + map[x + 1][y]);
            cmp_max(sum + map[x + 1][y + 2]);
        }
    }
}

void sum_type_i(int x, int y)
{
    int sum = 0;
    if (x < n - 3)
    {
        sum = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 3][y];
        cmp_max(sum);
    }
    if (y < m - 3)
    {
        sum = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x][y + 3];
        cmp_max(sum);
    }
}

void sum_type_o(int x, int y)
{
    int sum = 0;
    if (x >= n - 1 || y >= m - 1)
        return;
    sum = map[x][y] + map[x][y + 1] + map[x + 1][y] + map[x + 1][y + 1];
    cmp_max(sum);
}

void sum_type_s_z(int x, int y)
{
    int sum = 0;
    //세로
    if(x < n - 1)
    {
        sum = map[x][y] + map[x + 1][y];
        if(y > 0)
        {
            if (x < n - 2)
                cmp_max(sum + map[x + 1][y - 1] + map[x + 2][y - 1]);
            if (x > 0)
                cmp_max(sum + map[x][y - 1] + map[x - 1][y - 1]);
        }
        if (y < m - 1)
        {
            if (x < n - 2)
                cmp_max(sum + map[x + 1][y + 1] + map[x + 2][y + 1]);
            if (x > 0)
                cmp_max(sum + map[x][y + 1] + map[x - 1][y + 1]);
        }
    }
    if (y < m - 1)
    {
        sum = map[x][y] + map[x][y + 1];
        if(x > 0)
        {
            if (y < m - 2)
                cmp_max(sum + map[x - 1][y + 1] + map[x - 1][y + 2]);
            if (y > 0)
                cmp_max(sum + map[x - 1][y] + map[x - 1][y - 1]);
        }
        if (x < n - 1)
        {
            if (y < m - 2)
                cmp_max(sum + map[x + 1][y + 1] + map[x + 1][y + 2]);
            if (y > 0)
                cmp_max(sum + map[x + 1][y] + map[x + 1][y - 1]);
        }
    }
}

void check_tetromino(int x, int y)
{
    sum_type_i(x, y);
    sum_type_o(x, y);
    sum_type_t_j_l(x, y);
    sum_type_s_z(x, y);
}

int main()
{
    cin >> n >> m;
    map.resize(n);
    for (int i = 0; i < n; i++)
    {
        map[i].resize(m);
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            check_tetromino(i, j);
    }
    cout << max_sum << '\n';
    return 0;
}