/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1976                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1976                           #+#        #+#      #+#    */
/*   Solved: 2024/10/06 23:38:06 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int> > cities;
vector<int> dest;

bool bfs(int start, int end)
{
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if(curr == end)
            return true;
        for (int i = 1; i <= n; i++)
            if (!visited[i] && cities[curr][i])
            {
                q.push(i);
                visited[i] = true;
            }
    }
    return false;
}

void cal_possible()
{
    bool isPossible = true;
    if(m > 1)
        for (int i = 0; i < m - 1; i++)
        {
            if (dest[i] == dest[i + 1])
                continue;
            isPossible = bfs(dest[i], dest[i + 1]);
            if(!isPossible)
                break;
        }
    if(isPossible)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{

    cin >> n >> m;
    cities.resize(n + 1, vector<int>(n + 1, 0));
    dest.resize(m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> cities[i][j];
        }
    for (int i = 0; i < m; i++)
        cin >> dest[i];
    cal_possible();

    return 0;
}