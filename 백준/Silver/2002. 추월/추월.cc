#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int find_index(vector<string> v, string s) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].compare(s) == 0)
            return i;
    }
    return -1;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, sol = 0;

    cin >> n;

    queue<string> q;
    vector<string> v(n);
    vector<bool> check(n, false);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v[i] = s;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        q.push(s);
    }
    for (int i = 0; i < n; i++)
    {
        if(check[i]) continue;
        while (!q.empty())
        {
            string f = q.front();
            q.pop();
            int index = find_index(v, f);
            if (v[i].compare(f) == 0 || check[index])
            break;
            check[index] = true;
            sol++;
        }
        if(q.empty()) break;
    }

    cout << sol << '\n';
    return 0;
}