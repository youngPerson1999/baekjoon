#include <iostream>
#include <vector>

using namespace std;

int n, max_h = 1000000000;
long long m;
vector<int> trees;

long long cal_sum(int h)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if(trees[i] - h > 0)
        {
            sum += trees[i] - h;
            if (sum > m)
                return sum;
        }
    }
    return sum;
}

int cal_max_h()
{
    int min_h = 1;
    int curr_h;
    while (min_h <= max_h)
    {
        curr_h = (min_h + max_h) / 2;
        long long sum = cal_sum(curr_h);
        if(sum == m)
            return curr_h;
        else if(sum < m)
            max_h = curr_h - 1;
        else
        {
            min_h = curr_h + 1;
        }
    }
    return max_h;
}

int main ()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    trees.resize(n);
    for (int i = 0; i < n; i++)
        cin >> trees[i];
    cout << cal_max_h() << '\n';
}