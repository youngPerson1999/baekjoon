#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

// class chess_board{
//     private:
//         int size;
//         vector<vector<int> > board;
//     public:
//         int getSize();
//         void setSize()
// }

int calSol(int size, pair<int, int> c_knight, pair<int, int> goal)
{
    vector<vector<int> > chess_board(size, vector<int> (size, 0));
    queue<pair<int, int> > q;
    q.push(c_knight);
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x < 0 || y < 0 || x >= size || y >= size)
            continue;
        if(x == goal.first && y == goal.second)
            break;
        for (int i = 0; i < 8; i++)
        {
            pair<int, int> move;
            int new_x, new_y;
            // 1,2 2,1 1,-2 2,-1  -1,-2 -2,-1  -1,2   -2,1
            //대충 규칙 찾아서 이동할거 만들어줌!
            if(i %2==0){
                move.first = 1;
                move.second = 2;
            }
            else{
                move.first = 2;
                move.second = 1;
            }
            if(i > 3)
                move.first *= -1;
            if(i>=2 && i <= 5)
                move.second *= -1;
            new_x = x + move.first;
            new_y = y + move.second;
            if(new_x >= 0 && new_x < size && new_y >= 0 && new_y < size){
                if(chess_board[new_x][new_y] == 0){ //대충 방문 체크 역할
                    q.push(make_pair(new_x, new_y));
                    chess_board[new_x][new_y] = chess_board[x][y] + 1;
                }
            }
        }
    }
    return chess_board[goal.first][goal.second];
}

int main()
{
    int t;

    cin >> t;
    for (int i = 0; i < t;i++){
        int size;
        pair<int, int> cur_knight;
        pair<int, int> goal;
        cin >> size;
        cin >> cur_knight.first >> cur_knight.second;
        cin >> goal.first >> goal.second;
        cout << calSol(size, cur_knight, goal) << "\n";
    }

        return 0;
}