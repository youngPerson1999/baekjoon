#include<iostream>
#include<utility>
#include<queue>

using namespace std;

int bfs(int a,int b){

    queue<pair<long long,int> > q;
    //first -> value, second -> dist
    q.push(make_pair(a,1));

    int min = 0;
    while (!q.empty()){
        long cur = q.front().first;
        int cur_d = q.front().second;
        // cout<<cur<<"\n";
        if(cur==b) return cur_d;
        q.pop();
        if(cur*2<=b){
            q.push(make_pair(cur*2,cur_d+1));
        }
        if(cur*10+1<=b){
            q.push(make_pair(cur*10+1,cur_d+1));
        }
    }
    return -1;
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int a,b,t;

    cin>>a>>b;
    
    cout<<bfs(a,b);

    return 0;
}
