#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int compare(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;

    vector<pair<int, int> > cv(k);

    for (int i = 0; i < k; i++) {
        cin >> cv[i].second >> cv[i].first;
    }
    sort(cv.begin(), cv.end(), compare);

    //가장 낮은 도수
    int c;
    int sum_m = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for (int i = 0; i < k; i++)
    {
        c = cv[i].first;
        if(pq.size() < n) {
            sum_m += cv[i].second;
            pq.push(make_pair(cv[i].second, cv[i].first));
        }
        else {
            if(pq.top().first < cv[i].second) {
                sum_m -= pq.top().first;
                pq.pop();
                sum_m += cv[i].second;
                pq.push(make_pair(cv[i].second, cv[i].first));
            }
        }
        if(pq.size() == n && sum_m >= m) {
            break;
        }
    }
    if(sum_m >= m) {
        cout << c << "\n";
    }
    else {
        cout << "-1\n";
    }

    return 0;
}