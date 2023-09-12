#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> sols;
void print_solution()
{
    int sol_min, sol_max;

    int start = 0, end = n - 1;
    sol_min = sols[start];
    sol_max = sols[end];
    int min_aws = 2000000001;
    while (end > start)
    {
        int cur_aws = sols[start] + sols[end];
        if (abs(cur_aws) < min_aws)
        {
            sol_min = sols[start];
            sol_max = sols[end];
            min_aws = abs(sol_min + sol_max);
            if (cur_aws == 0)
            {
                sol_min = sols[start];
                sol_max = sols[end];
                break;
            }
        }
        if (cur_aws < 0)
        {
            start++;
        }
        else if (cur_aws > 0)
        {
            end--;
        }
        }
    
    cout << sol_min << " " << sol_max << "\n";
}

int main()
{

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    sols.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sols[i];
    }
    sort(sols.begin(), sols.end());
    print_solution();
    return 0;
}