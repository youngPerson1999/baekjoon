#include <iostream>
#include <vector>

using namespace std;

int check_column(int **candy, int n){
    //max[0]: C, [1]: P, [2]: Z, [3]: Y
    vector<int> max(4,0), tmp(4,0);
    for (int i = 0; i < n; i++)
    {
        tmp[0] = tmp[1] = tmp[2] = tmp[3] = 0;
        for (int j = 1; j < n; j++)
        {
            int c = candy[j][i];
            int before = candy[j - 1][i];
            if (c == before && tmp[c] == 0){
                tmp[c] = 2;
                continue;
            }
            else if (c == before){
                tmp[c]++;
                if (tmp[c] > max[c])
                    max[c] = tmp[c];
            }
            else if(c != before){
                if(tmp[before] > max[before])
                    max[before] = tmp[before];
                tmp[before] = 0;
            }
        }
    }
    int rst = 0;
    for (int i = 0; i < 4; i++)
        if(max[i] > rst)
            rst = max[i];
    return rst;
}

int check_row(int **candy, int n){
    //max[0]: C, [1]: P, [2]: Z, [3]: Y
    vector<int> max(4,0), tmp(4,0);

    // row 확인
    for (int i = 0; i < n; i++)
    {
        tmp[0] = tmp[1] = tmp[2] = tmp[3] = 0;
        for (int j = 1; j < n; j++)
        {
            int c = candy[i][j];
            int before = candy[i][j - 1];
            if (c == before && tmp[c] == 0){
                tmp[c] = 2;
                continue;
            }
            else if (c == before){
                tmp[c]++;
                if (tmp[c] > max[c])
                    max[c] = tmp[c];
            }
            else if(c != before){
                if(tmp[before] > max[before])
                    max[before] = tmp[before];
                tmp[before] = 0;
            }
        }
    }
    int rst = 0;
    for (int i = 0; i < 4; i++)
        if(max[i] > rst)
            rst = max[i];
    return rst;
}

int main(){

    int n, rst = 0;

    cin >> n;

    int **candy = new int*[n];

    for (int i = 0; i < n; i++){
        candy[i] = new int[n];
        char c;
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            if(c == 'C')
                candy[i][j] = 0;
            else if(c == 'P')
                candy[i][j] = 1;
            else if(c == 'Z')
                candy[i][j] = 2;
            else
                candy[i][j] = 3;
        }

    }
    
    //행(가로) 바꾸기 -> 열(세로)확인
    for (int i = 0; i < n; i++){
        for (int j = 1; j < n; j++){
            int tmp = candy[i][j];
            candy[i][j] = candy[i][j - 1];
            candy[i][j - 1] = tmp;
            tmp = check_column(candy, n);
            if(tmp > rst)
                rst = tmp;
            tmp = check_row(candy, n);
            if(tmp > rst)
                rst = tmp;
            tmp = candy[i][j];
            candy[i][j] = candy[i][j - 1];
            candy[i][j - 1] = tmp;
        }
        if(rst == n){
            cout << rst << "\n";
            return 0;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 1; j < n; j++){
            int tmp = candy[j][i];
            candy[j][i] = candy[j - 1][i];
            candy[j - 1][i] = tmp;
            tmp = check_column(candy, n);
            if(tmp > rst)
                rst = tmp;
            tmp = check_row(candy, n);
            if(tmp > rst)
                rst = tmp;
            tmp = candy[j][i];
            candy[j][i] = candy[j - 1][i];
            candy[j - 1][i] = tmp;
        }
        if(rst == n){
            cout << rst << "\n";
            return 0;
        }
    }
    cout << rst << "\n";
    return 0;
}

/*
일단 n*n을 전부 돈다
이유: 3*3부터 시작 -> 안바뀐행, 안바뀌는 열이 존재! <- 미리 체크한다는 의미
여기서 n이 나와버리면 굳이 바꾸고 검사할 필요가 없음!
이러면 만약 가로로 0<->1 바꾸면 세로 0번, 1번만 검사해보면 됨!  n=5 
rst=n이면 끝내버리기
왜냐면 2,3,4번째 열은 기존의 맵과 동일하기 때문!
실행시간은 적을듯
*/