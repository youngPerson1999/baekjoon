/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11000                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11000                          #+#        #+#      #+#    */
/*   Solved: 2024/10/31 23:26:23 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;

bool compare(pair<int, int>a, pair<int, int>b){
    if(a.first < b.first) return true;
    else if(a.first==b.first){
        return a.second < b.second;
    }
    else
        return false;
}

int main(){
    cin >> n;
    vector<pair<int, int> > lectures(n);
    priority_queue< int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        lectures[i] = make_pair(a, b);
    }
    sort(lectures.begin(), lectures.end(), compare);
    pq.push(lectures[0].second);
    for (int i = 1; i < n; i++)
    {
        pq.push(lectures[i].second);
        if (lectures[i].first >= pq.top())
            pq.pop();
    }
    cout << pq.size() << '\n';
    return 0;
}