#include <iostream>
#include <string>
#include <vector>

using namespace std;

string a, b;
int max_same = 0;
vector<vector<int> > dp(4001, vector<int>(4001, 0));
void sol(){
    int a_size = a.size(), b_size = b.size();
    for (int i = 1; i <= a_size; i++)
    {
        for (int j = 1; j <= b_size; j++)
        {
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max_same = max(max_same, dp[i][j]);
            }
        }
    }
    cout << max_same << "\n";
}
int main()
{
    cin >> a >> b; 
    sol();
    return 0;
}