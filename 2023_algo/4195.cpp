#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
map<string, int> names;
vector<int> cnt, parent;

int find_parent(int n)
{
    if (parent[n] == n)
        return n;
    parent[n] = find_parent(parent[n]);
    return parent[n];
}

int size_of_network(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);
    // same set
    if (a == b)
        return cnt[a];
    //a가 뒤에 있으면 부모노드 idx 바꿔서 트리 유지
    if(a > b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    parent[b] = a;
    cnt[a] += cnt[b];

    return cnt[a];
}

void virtual_friend(int f)
{
    for (int i = 0; i < f; i++)
    {
        string a, b;
        cin >> a >> b;
        if (names.find(a) == names.end())
            names[a] = names.size();
        if (names.find(b) == names.end())
            names[b] = names.size();
        cout << size_of_network(names[a], names[b]) << "\n";
    }
}

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int f;
        cin >> f;
        names.clear();
        cnt.resize(2 * f + 2);
        parent.resize(2 * f + 2);
        for (int i = 0; i < 2 * f + 1; i++)
        {
            cnt[i] = 1;
            parent[i] = i;
        }
        virtual_friend(f);
    }
    return 0;
}