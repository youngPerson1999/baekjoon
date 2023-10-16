#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pos;
vector<int> neg;
int main()
{
    int n, tmp;
    long long sol = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if(tmp <= 0)
            neg.push_back(tmp);
        else if(tmp == 1)
            sol++;
        else
            pos.push_back(tmp);
    }

    int p_size = pos.size(), n_size = neg.size();
    if(p_size > 0)
    {
        sort(pos.begin(), pos.end(), greater<int>());
        for (int i = 0; i < p_size; i += 2)
        {
            if (i + 1 < p_size)
                sol += pos[i] * pos[i + 1];
            else
                sol += pos[i];
        }
    }

    if (n_size > 0)
    {
        sort(neg.begin(), neg.end());
        for (int i = 0; i < n_size; i += 2)
        {
            if (i + 1 < n_size)
                sol += neg[i] * neg[i + 1];
            else
                sol += neg[i];
        }
    }

    cout << sol << "\n";

    return 0;
}