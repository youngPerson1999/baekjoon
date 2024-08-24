#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    string key, value;
    unordered_map<string, string> um;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> key >> value;
        um.insert({key, value});
    }
    for (int i = 0; i < m;i++)
    {
        cin >> key;
        cout << um[key] << '\n';
    }

    return 0;
}