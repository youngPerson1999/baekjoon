/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14938                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14938                          #+#        #+#      #+#    */
/*   Solved: 2024/10/11 20:33:58 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#define MAX 1000000000

using namespace std;

int n, m, r;
vector<vector<int> > grounds;
vector<int> items;

void floyd()
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                grounds[i][j] = min(grounds[i][j], grounds[i][k] + grounds[k][j]);        
}

int get_items(int start)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if(grounds[start][i] <= m)
            sum += items[i];
    }
    return sum;
}

int main()
{
    cin >> n >> m >> r;
    items.resize(n);
    grounds.resize(n, vector<int>(n, MAX));
    int max_item = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> items[i];
        grounds[i][i] = 0;
    }
    for (int i = 0; i < r; i++)
    {
        int x, y, l;
        cin >> x >> y >> l;
        grounds[--x][--y] = l;
        grounds[y][x] = l;
    }
    floyd();
    for (int i = 0; i < n; i++)
    {
        int curr_items = get_items(i);
        max_item = curr_items > max_item ? curr_items : max_item;
    }
    cout << max_item << '\n';
    return 0;
}