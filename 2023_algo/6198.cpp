#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long cnt = 0, n;
    stack<int> s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        while(!s.empty() && s.top() <= cur)
        {
            s.pop();
            cnt += s.size();
        }
        s.push(cur);
    }
    while(!s.empty()){
        s.pop();
        cnt += s.size();
    }

    cout << cnt << "\n";
    return 0;
}