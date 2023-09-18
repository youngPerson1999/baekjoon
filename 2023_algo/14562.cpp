#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int s, t;

int fillCount(){
    int rst = 0;
    queue<tuple<int, int, int> > q;
    q.push(make_tuple(s,t, 0));

    while (!q.empty())
    {
        int cur_s = get<0>(q.front());
        int cur_t = get<1>(q.front());
        int cur_c = get<2>(q.front());
        q.pop();
        if (cur_s > cur_t)
            continue;
        if(cur_s == cur_t){
            rst = cur_c;
            break;
        }
        q.push(make_tuple(2 * cur_s, cur_t + 3, cur_c + 1));
        q.push(make_tuple(cur_s + 1, cur_t, cur_c + 1));
    }
    return rst;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> t;
        cout << fillCount() << "\n";
    }
    return 0;
}