#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define WHEEL 4
#define TOOTH 8

using namespace std;


vector<vector<int>> wheels(WHEEL, vector<int>(TOOTH));
//3번이 오른쪽 맞닿고, 7번이 왼쪽 맞닿음

//-1 = 반시계, 1 = 시계
//1일때 0->1, -1일때 1->0
vector<int> rotation(vector<int> w, int dir){
    vector<int> rst = w;
    if (dir == -1)
    {
        copy(w.begin() + 1, w.end(), rst.begin());
        rst[7] = w[0];
    }
    else if(dir == 1){
        copy(w.begin(), w.end() - 1, rst.begin() + 1);
        rst[0] = w[7];
    }
    return rst;
}

//1번이 왼쪽 2번이 오른쪽
bool is_rotatable (vector<int> w1, vector<int> w2) {
    return w1[2] != w2[6];
}

vector<int> rotate_dir(int start, int s_dir) {
    vector<int> dirs = {0, 0, 0, 0};
    dirs[start] = s_dir;
    // 오른쪽 1-2 비교
    for (int i = start + 1; i < WHEEL; i++)
    {
        if (is_rotatable(wheels[i - 1], wheels[i]))
            dirs[i] = dirs[i - 1] * (-1);
        else
            break;
    }
    // 왼쪽 2-1 비교
    for (int i = start - 1; i >= 0; i--)
    {
        if (is_rotatable(wheels[i], wheels[i + 1]))
            dirs[i] = dirs[i + 1] * (-1);
        else
            break;
    }
    return dirs;
}

//0 -> 7 시계방향
int main()
{

    string s;
    int k, w, d;
    for (int i = 0; i < WHEEL; i++)
    {
        cin >> s;
        for (int j = 0; j < TOOTH; j++)
            wheels[i][j] = s[j] - '0';
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> w >> d;
        vector<int> dirs = rotate_dir(w - 1, d);
        for (int j = 0; j < WHEEL; j++)
        {
            wheels[j] = rotation(wheels[j], dirs[j]);
        }
    }

    int rst = 0;
    for (int i = 0; i < WHEEL; i++)
        if(wheels[i][0] > 0)
            rst += (1 << i);
    cout << rst << '\n';
}