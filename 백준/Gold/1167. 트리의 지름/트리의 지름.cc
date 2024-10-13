/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1167                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1167                           #+#        #+#      #+#    */
/*   Solved: 2024/10/13 22:24:47 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

int v;
vector<vector<pair<int, int> > > tree;
vector<bool> visited;
int sol = 0, solNode;
void dfs(int s, int r){
    if(r > sol)
    {
        sol = r;
        solNode = s;
    }
    visited[s] = true;
    int size = tree[s].size();
    for (int i = 0; i < size; i++){
        pair<int, int> t = tree[s][i];
        if (!visited[t.first]){
            dfs(t.first, r + t.second);
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v;
    tree.resize(v + 1);
    for (int i = 0; i < v; i++)
    {
        int curr, input = 0, idx = 0, node;
        cin >> curr;
        while(input != -1)
        {
            idx++;
            cin >> input;
            if (idx % 2 == 1)
                node = input;
            else
            {
                tree[node].push_back({curr, input});
            }
        }
    }

    visited = vector<bool>(v + 1, false);
    dfs(1, 0);
    visited = vector<bool>(v + 1, false);
    dfs(solNode, 0);
    cout << sol << "\n";
    return 0;
}