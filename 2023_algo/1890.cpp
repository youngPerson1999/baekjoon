#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int> > board;
vector<vector<long long> > sol;

void fillSol(int x, int y){
    int i = x, j = y;
    int jump = board[i][j];
    // 아래로만
    if(i + jump < n)
        sol[i + jump][j] += sol[i][j];
    //오른쪽
    if (j + jump < n)
        sol[i][j + jump] += sol[i][j];
}

void calPath(){
    //하나씩 돌면서 아래 오른쪽 체크 해줄서임
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i == n - 1 && j == n - 1)
                break;
            if (sol[i][j] != 0)
                fillSol(i, j);
        }
    }
}

int main(){

    cin>>n;

    for (int i = 0; i < n;i++){
        vector<int> row(n, 0);
        vector<long long> solRow(n, 0);
        sol.push_back(solRow);
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            row[j] = t;
        }
        board.push_back(row);
    }
    sol[0][0] = 1;
    calPath();

    cout << sol[n - 1][n - 1] << "\n";
    return 0;
}