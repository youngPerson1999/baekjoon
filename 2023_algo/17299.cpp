#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> cnt(1000001, 0);
    vector<int> num(n), sol(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        cnt[num[i]]++;
    }
    for(int i = 0; i < n; i++)
    {
        int j = 1, cur = cnt[num[i]];
        while (!s.empty() && cnt[s.top()] < cur)
        {
            s.pop();
            while (sol[i - j] != -1)
                j++;
            sol[i - j] = num[i];
            j++;
        }
        s.push(num[i]);
    }
    for(int i = 0; i < n; i++)
        cout << sol[i] << " ";

    return 0;
}
