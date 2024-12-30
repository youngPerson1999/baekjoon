#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> A;
int N, M;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int> >, cmp > pq;

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    A.resize(N + 1);
    for(int i= 1; i <= N; i++) {
        cin>>A[i];
        pq.push(make_pair(A[i], i));
    }
    cin>>M;
    for(int i = 0; i < M; i++) {
        int t, a, b;
        cin>>t;
        if(t == 2) {
            pair<int, int> curr = pq.top();
            while(A[curr.second] != curr.first) {
                pq.pop();
                curr = pq.top();
            }
            cout<<pq.top().second<<'\n';
        }
        else {
            cin >> a >> b;
            A[a] = b;
            pq.push(make_pair(b, a));
        }
    }
        
    
    return 0;
}