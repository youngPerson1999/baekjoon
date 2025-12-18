#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
vector<vector<int>> monun;

void put_rect(pair<int, int> x, pair<int, int> y) {
    for (int i = x.first; i < y.first; i++) {
        for (int j = x.second; j < y.second; j++)
            monun[i][j] = -1;
    }
}

bool is_pushable(int x, int y, int n, int m) {
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return monun[x][y] == 0;
}

int visit_bfs(pair<int, int> start, int n, int m) {
    int size = 0;
    queue<pair<int, int>> q;
    q.push(start);
    monun[start.first][start.second] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        size++;
        q.pop();
        if(is_pushable(x-1,y,n,m)){
            q.push(make_pair(x - 1, y));
            monun[x - 1][y] = 1;
        }
        if(is_pushable(x+1,y,n,m)){
            q.push(make_pair(x + 1, y));
            monun[x + 1][y] = 1;
        }
        if(is_pushable(x,y-1,n,m)){
            q.push(make_pair(x, y-1));
            monun[x][y-1] = 1;
        }
        if(is_pushable(x,y+1,n,m)){
            q.push(make_pair(x, y+1));
            monun[x][y+1] = 1;
        }
    }

    return size;
}

pair<int, int> find_next_start(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(monun[i][j] == 0)
                return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

int main () {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int m, n, k;
    vector<int> size;
    cin >> m >> n >> k;

    monun.resize(n, vector<int>(m, 0));
    for (int i = 0; i < k; i++) {
        pair<int, int> x, y;
        cin >> x.first >> x.second >> y.first >> y.second;
        put_rect(x, y);
    }
    pair<int, int> start = find_next_start(n, m);
    while (start.first != -1)
    {
        size.push_back(visit_bfs(start, n, m));
        start = find_next_start(n, m);
    }
    sort(size.begin(), size.end());
    cout << size.size() << '\n';
    for (int i = 0; i < size.size(); i++)
        cout << size[i] << ' ';
    cout << '\n';
    return 0;
}