#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
int n;
vector<int> num(101);
bool dfs(int start, int next, vector<bool> v)
{
    if(v[next] == false)
    {
        v[next] = true;
        return dfs(start, num[next], v);
    }
    else{
        if(start==next)
            return true;
        return false;
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];

    vector<int> s;
    for (int i = 1; i <= n; i++)
    {
        vector<bool> visited(n + 1, false);
        if (dfs(i, i, visited))
            s.push_back(i);
    }
    cout << s.size() << "\n";
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << "\n";
    return 0;
}