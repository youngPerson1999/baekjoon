#include <iostream>
#include <vector>
#include <utility>
#define SIZE 19

using namespace std;

vector<vector<int> > goBoard(SIZE + 1);

//x -> 세로, y -> 가로
int check_win(int x, int y){
    int count = 1, i, color = goBoard[x][y];
    //오른쪽, 아래, 오른쪽 위, 아래 대각선 검사
    //right
    if(y < SIZE - 4){
        //왼쪽에 똑같은게 있으면 셀 필요 없음.
        if(y > 0 && goBoard[x][y - 1]==color)
            count = 1;
        else
            for (i = y + 1; i < SIZE; i++)
            {
                if(goBoard[x][i] == color)
                    count++;
                else
                    break;
            }
        if (count == 5)
            return color;
        else
            count = 1;
    }
    //아래
    if(x < SIZE - 4){
        //위에 똑같은게 있으면 셀 필요 없음
        if(x > 0 && goBoard[x - 1][y] == color)
            count = 1;
        else
            for (int i = x + 1; i < SIZE; i++){
                if(goBoard[i][y] == color)
                    count++;
                else
                    break;
            }
        if (count == 5)
            return color;
        else
            count = 1;
    }
    //위대각선
    if(x > 3 && y < SIZE - 4){
        if(y > 0 && x < SIZE - 1 && goBoard[x + 1][y - 1] == color)
            count = 1;
        else
            for (int i = 1; i < SIZE - 1; i++){
                if (goBoard[x - i][y + i]== color)
                    count++;
                else
                    break;
                if (x - i <= 0 || y + i >= SIZE - 1)
                    break;
        }
        if (count == 5)
            return color;
        else
            count = 1;
    }
    //아래 대각선 보수적으로 5개 없으면 짤라
    if(x < SIZE - 4 && y < SIZE - 4){
        if(x > 0 && y > 0 && goBoard[x - 1][y - 1] == color)
            count = 1;
        else
            for (int i = 1; i < SIZE - 1; i++){
                if (goBoard[x + i][y + i]== color)
                    count++;
                else
                    break;
                if (x + i >= SIZE - 1 || y + i >= SIZE - 1)
                    break;
            }
        if (count == 5)
            return color;
        else
            count = 1;
    }
    return 0;
}

int main(){
    
    vector<pair<int, int> > location;
    for (int i = 0; i < SIZE; i++)
    {
        vector<int> row(SIZE + 1, 0);
        for (int j = 0; j < SIZE; j++)
        {
            cin >> row[j];
            if (row[j] != 0)
                location.push_back(make_pair(i, j));
        }
        goBoard[i] = row;
    }
    vector<int> r(SIZE + 1, 0);
    goBoard[SIZE] = r;
    int sizeOfLoc = location.size();
    int color, idx;
    for (int i = 0; i < sizeOfLoc; i++)
    {
        color = check_win(location[i].first, location[i].second);
        idx = i;
        // cout << location[i].first << " " << location[i].second << "\n";
        if (color == 1 || color == 2)
            break;
    }
    cout << color << "\n";
    if (color != 0)
        cout << location[idx].first + 1 << " " << location[idx].second + 1 << "\n";
    return 0;
}
