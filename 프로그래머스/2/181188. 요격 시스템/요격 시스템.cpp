#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

struct Node {
    int second;
    int first;
    
    Node(int v, int i) : second(v), first(i) {}
};

struct CompareNode {
    bool operator()(const Node& n1, const Node& n2) {
        return n1.second > n2.second;  // 오름차순 정렬
    }
};

int solution(vector<vector<int> > targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), compare);
    priority_queue<Node, vector<Node>, CompareNode > pq;
    pq.push(Node(targets[0][1], 0));
    int t_size = targets.size(), last = 0;
    for(int i = 1; i < t_size; i++)
    {
        pq.push(Node(targets[i][1], targets[i][0]));
        if(targets[i][0] >= pq.top().second)
        {
            if(pq.top().first >= last)
            {
                answer++;
                last = pq.top().second;
            }
            pq.pop();
        }
            
    }
    while(!pq.empty()) {
        if(pq.top().first >= last)
            {
                answer++;
                last = pq.top().second;
            }
        pq.pop();
    }
    return answer;
}