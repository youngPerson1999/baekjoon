#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int n;
vector<vector<int> > house;
vector<vector<int> > sol;
//state 0: 가로, 1: 세로, 2: 대각선
pair<pair<int, int>, int > make_input(int x, int y, int state){
    return make_pair(make_pair(x, y), state);
}

int cal_sol(){
    queue<pair<pair<int, int>, int> > q;
    //1st position -> (0,0)-(0,1)
    //q에는 오른쪽 || 밑을 넣기
    q.push(make_input(0, 1, 0));
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int state = q.front().second;
        q.pop();
        // 대각선 이동
        if (x + 1 < n && y + 1 < n && house[x][y + 1] == 0 && house[x + 1][y] == 0 && house[x + 1][y + 1]==0){
            sol[x + 1][y + 1]++;
            q.push(make_input(x + 1, y + 1, 2));
        }
        //가로 이동
        if (state == 0 || state == 2)
        {
            if (y + 1 < n && house[x][y + 1] == 0)
            {
                sol[x][y + 1]++;
                q.push(make_input(x, y + 1, 0));
            }
        }
        //세로 이동
        if (state == 1 || state == 2){
            if (x + 1 < n && house[x + 1][y] == 0){
                sol[x + 1][y]++;
                q.push(make_input(x + 1, y, 1));
            }
        }
    }
    return sol[n - 1][n - 1];
}

int main()
{

    cin >> n;
    house.resize(n, vector<int>(n));
    sol.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
            cin >> house[i][j];

    cout << cal_sol() << "\n";
    return 0;
}