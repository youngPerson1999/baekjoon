#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int n;
vector<vector<int>> sqr;
vector<vector<int>> pos;

int fill_pos(int x, int y, int p) {
    int rst = 0;
    if(x + p < n && pos[x + p][y] != 1) {
        pos[x + p][y] = 1;
        rst += 1;
    }
    if(y + p < n && pos[x][y + p] != 1) {
        pos[x][y + p] = 1;
        rst += 2;
    }
    //0 안됨, 1 x방향 됨, 2 y방향 됨, 3 둘다됨
    return rst;
}

bool is_possible() {
    queue<pair<int, int>> q;
    int l = fill_pos(0, 0, sqr[0][0]);
    if(l % 2 == 1) {
        q.push(make_pair(sqr[0][0], 0));
    }
    if(l >= 2) {
        q.push(make_pair(0, sqr[0][0]));
    }
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        l = fill_pos(x, y, sqr[x][y]);
        if(l % 2 == 1) {
            q.push(make_pair(x + sqr[x][y], y));
        }
        if(l >= 2) {
            q.push(make_pair(x, y + sqr[x][y]));
        }
    }
    return pos[n - 1][n - 1] == 1;
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    sqr.resize(n, vector<int>(n));
    pos.resize(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> sqr[i][j];

    if(is_possible()) {
        cout << "HaruHaru\n";
    }
    else {
        cout << "Hing\n";
    }
    return 0;
}