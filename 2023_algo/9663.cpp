#include <iostream>
#include <vector>

using namespace std;

int n, rst = 0;
vector<int> chess;

bool check_pos(int cur_q, int cur_i){
    int dx, dy;
    for (int i = 0; i < cur_q; i++)
    {
        dx = abs(chess[i] - cur_i);
        dy = abs(i - cur_q);
        if (chess[i] == cur_i || dx == dy)
            return false;
    }
    return true;
}

void cal_queen(int cur_q){
    if(cur_q == n){
        rst++;
    }
    else{
        for (int i = 0; i < n; i++){
            if(check_pos(cur_q, i)){
                chess[cur_q] = i;
                cal_queen(cur_q + 1);
            }
        }
    }
}

int main()
{
    cin >> n;
    chess.resize(n, 0);
    cal_queen(0);
    cout << rst << "\n";
    return 0;
}