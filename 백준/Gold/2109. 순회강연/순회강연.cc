/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2109                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2109                           #+#        #+#      #+#    */
/*   Solved: 2024/11/04 00:03:27 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<pair<int, int> > lectures;
vector<int> pay(10001, 0);
//오름차순
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;   // second가 같다면 first가 작은 것이 앞으로
        }
        return a.second > b.second;     // second가 작을수록 우선
    }
};
 priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;


bool compare(pair<int, int> a, pair<int, int> b){

    if(a.first==b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}



int main()
{
    cin >> n;
    lectures.resize(n);
    for (int i = 0; i < n; i++)
    {
        int d, p;
        cin >> p >> d;
        lectures[i] = make_pair(d, p);
    }
    if(n == 0){
        cout << 0 << '\n';
        return 0;
    }
    sort(lectures.begin(), lectures.end(), compare);
    pq.push(lectures[0]);
    for (int i = 1; i < n; i++)
    {
        int d = lectures[i].first;
        int p = lectures[i].second;
        if (pq.size() >= d)
        {
            int top_p = pq.top().second;
            if(top_p < p)
                pq.pop();
            else
                continue;
        }
        pq.push(lectures[i]);
    }
    int sum = 0;
    while(!pq.empty()){
        sum += pq.top().second;
        pq.pop();
    }
    cout << sum << '\n';
    return 0;
}