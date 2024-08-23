#include <iostream>
#include <string>
#include <vector>

using namespace std;

string a, b, c;
int max_same = 0;
vector<vector<vector<int> > > dp(101, vector<vector<int> >(101, vector<int> (101, 0)));
void sol(){
    int a_size = a.size(), b_size = b.size(), c_size = c.size();
    for (int i = 1; i <= a_size; i++)
    {
        for (int j = 1; j <= b_size; j++)
        {
            for (int k = 1; k <= c_size; k++)
            {
                if(a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]){
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    max_same = max(max_same, dp[i][j][k]);
                }
                else
                {
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                }
                
            }
        }
    }
    cout << max_same << "\n";
}
int main()
{
    cin >> a >> b >> c; 
    sol();
    return 0;
}
duddls4552