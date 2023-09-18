#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n;
vector<pair<int, int> > ts;
bool cmp(pair<int, int>a, pair<int, int> b){
    return a.second > b.second;
}
int check_time()
{
    int start = ts[0].second - ts[0].first;
    for (int i = 1; i < n; i++)
    {
        int cur_start = ts[i].second - ts[i].first;
        int cur_end = ts[i].second;
        if (start < cur_end)
            start -= ts[i].first;
        else
            start = cur_start;        
    }
    if(start < 0)
        return -1;
    return start;
}
int main()
{
    cin >> n;
    ts.resize(n);
    int t, s;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> s;
        ts[i] = make_pair(t, s);
    }
    sort(ts.begin(), ts.end(), cmp);
    cout << check_time() << "\n";
    return 0;
}