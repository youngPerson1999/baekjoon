#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> wines;
vector<vector<int> > sol(3);

int max_tri(int a, int b, int c) {
    return max(a, max(b, c));
}

void sol_dp(int i) {
    sol[0][i] = max_tri(sol[0][i - 1], sol[1][i - 1], sol[2][i - 1]);
    sol[1][i] = sol[0][i - 1] + wines[i];
    sol[2][i] = sol[1][i - 1] + wines[i];
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    wines.resize(n);
    //해당 인덱스(i)가 포함 안됐을때 최적값
    sol[0].resize(n, 0);
    //해당 인덱스(i)가 첫번째 잔일때 최적값
    sol[1].resize(n, 0);
    //해당 인덱스(i)가 두번째잔(다음잔 무조건 안마심)일때 최적값
    sol[2].resize(n, 0);
    

    for (int i = 0; i < n; i++)
    {
        cin >> wines[i];
    }
    if (n == 1)
    {
        cout << wines[0] << '\n';
        return 0;
    }
    sol[1][0] = wines[0];
    sol[2][0] = wines[0];
    sol[0][1] = wines[0];
    sol[1][1] = wines[1];
    sol[2][1] = wines[0] + wines[1];
    // 2부터 시작인 이유: 0-1번은 이미 정해져있음(sol[0][0] = 0, sol[1][0] = 0, sol[2][0] = wines[0])
    for (int i = 2; i < n; i++)
        sol_dp(i);
    int max_sol = max_tri(sol[0][n - 1], sol[1][n - 1], sol[2][n - 1]);
    cout << max_sol << '\n';

    return 0;
}