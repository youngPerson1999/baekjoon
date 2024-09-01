#include<iostream>
#include<vector>

using namespace std;

vector<int> min_dp(3, 0), max_dp(3, 0), arr(3, 0), prev_min(3, 0), prev_max(3, 0);
int n;

int find_min_num(int y)
{
    if (y == 0)    
    {
        return prev_min[0] < prev_min[1] ? prev_min[0] : prev_min[1];
    }
    else if (y == 1)
    {
        int min_n = prev_min[0];
        for (int i = 0; i < 3; i++) {
            if (prev_min[i] < min_n)
            {
                min_n = prev_min[i];
            }
        }
        return min_n;
    }
    else
    {
        return prev_min[2] < prev_min[1] ? prev_min[2] : prev_min[1];
    }
}

int find_max_num(int y)
{
    if (y == 0)    
    {
        return prev_max[0] > prev_max[1] ? prev_max[0] : prev_max[1];
    }
    else if (y == 1)
    {
        int max_n = prev_max[0];
        for (int i = 1; i < 3; i++) {
            if (prev_max[i] > max_n) {
                max_n = prev_max[i];
            }
        }
        return max_n;
    }
    else
    {
        return prev_max[2] > prev_max[1] ? prev_max[2] : prev_max[1];
    }
}

void cal_dp(int idx)
{
    if (idx == 0)
    {
        for (int j = 0; j < 3; j++)
        {
            max_dp[j] = min_dp[j] = arr[j];
        }
    }
    else if (idx <= n-1)
    {
        for (int j = 0; j < 3; j++)
        {
            prev_min[j] = min_dp[j];
            prev_max[j] = max_dp[j];
        }
        for (int j = 0; j < 3; j++)
        {
            min_dp[j] = arr[j] + find_min_num(j);
            max_dp[j] = arr[j] + find_max_num(j);
        }
    }
}

void print_sol()
{
    int max_sol = 0, min_sol = 100000 * 9;;
    for (int i = 0; i < 3; i++)
    {
        max_sol = max_dp[i] > max_sol ? max_dp[i] : max_sol;
        min_sol = min_dp[i] < min_sol ? min_dp[i] : min_sol;
    }
    cout << max_sol << ' ' << min_sol << '\n';
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> arr[j];
        cal_dp(i);
    }
    print_sol();

    return 0;
}