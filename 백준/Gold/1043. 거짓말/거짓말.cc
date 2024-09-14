/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1043                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1043                           #+#        #+#      #+#    */
/*   Solved: 2024/09/11 20:50:13 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k, max_lie = 0;
vector<vector<bool> > people(51, vector<bool>(51, false));
vector<vector<int> > parties;
vector<bool> visited(51, false);
queue<int> q;

void make_party(int num, int idx)
{
    int size = parties[idx].size();
    vector<int> party = parties[idx];
    for (int i = 0; i < size; i++)
    {
        int cur_per = party[i];
        for (int j = i; j < size; j++)
        {
            people[cur_per][party[j]] = true;
            people[party[j]][cur_per] = true;
        }
    }
}

void bfs ()
{
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if(people[front][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

bool check_liable(int idx)
{
    int size = parties[idx].size();
    for (int i = 0; i < size; i++)
    {
        if(visited[parties[idx][i]])
            return false;
    }
    return true;
}

int main()
{
    int tmp;
    cin >> n >> m >> k;
    parties.resize(m);
    for (int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        q.push(t);
        visited[t] = true;
    }
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        parties[i].resize(num);
        for (int j = 0; j < num; j++)
            cin >> parties[i][j];
        make_party(num, i);
    }
    bfs();
    for (int i = 0; i < m; i++)
    {
        if(check_liable(i))
            max_lie++;
    }
    cout << max_lie << '\n';
    return 0;
}