#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<long long>> v;
long long sol_stair()
{
    
    for (int i = 1; i < n; i++) {
        v[i][1] = v[i - 1][0];
        v[i][8] = v[i - 1][9];
        for (int j = 1; j <= 8; j++) {
            v[i][j - 1] = (v[i - 1][j] + v[i][j - 1]) % 1000000000;
            v[i][j + 1] = (v[i - 1][j] + v[i][j + 1]) % 1000000000;
        }
    }

    long long stair = 0;
    for (int i = 0; i <= 9; i++)
        stair += (v[n - 1][i] % 1000000000);
    return stair % 1000000000;
}

int main()
{

    cin >> n;
    v.resize(n + 1, vector<long long>(10, 0));
    for (int i = 1; i <= 9; i++)
        v[0][i] = 1;
    cout << sol_stair() << '\n';
}