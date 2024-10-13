/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 13023                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/13023                          #+#        #+#      #+#    */
/*   Solved: 2024/10/12 22:28:59 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<vector<int> > camp;
bool is_abcde = false;
void dfs(int start, int depth, vector<bool> visited)
{
    if(depth == 4 || is_abcde)
    {
        is_abcde = true;
        return;
    }
    visited[start] = true;
    int size = camp[start].size();
    for (int i = 0; i < size; i++)
        if(!visited[camp[start][i]])
            dfs(camp[start][i], depth + 1, visited);
    visited[start] = false;
}
int main()
{
    cin >> n >> m;
    camp.resize(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        camp[x].push_back(y);
        camp[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(n, false);
        dfs(i, 0, visited);
        if (is_abcde)
            break;
    }
    cout << is_abcde << '\n';
    return 0;
}