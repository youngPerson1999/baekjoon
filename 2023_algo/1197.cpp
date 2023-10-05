#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int v, e;
vector<vector<pair<int, int> > > map;
vector<bool> visited;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

void pq_push(int idx)
{
    int size = map[idx].size();
    
    for (int i = 0; i < size; i++)
    {
        if(!visited[map[idx][i].second])
        {
            pq.push(map[idx][i]);
        }
    }
}

long long solve()
{
    long long sol = 0;
    pq_push(1);
    visited[1] = true;
    while (!pq.empty())
    {
        pair<int, int> curr = pq.top();
        pq.pop();
        if (visited[curr.second])
            continue;
        sol += curr.first;
        visited[curr.second] = true;
        pq_push(curr.second);
    }
    return sol;
}
int main()
{
    int a, b, w;
    cin >> v >> e;
    map.resize(v + 1, vector<pair<int, int> >(0));
    visited.resize(v, false);
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> w;
        map[a].push_back(make_pair(w, b));
        map[b].push_back(make_pair(w, a));
    }
    cout << solve() << "\n";
    return 0;
}