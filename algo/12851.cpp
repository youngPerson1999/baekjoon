#include<iostream>
#include<utility>
#include<queue>
#include<algorithm>

using namespace std;
pair<int,int> check[200001];
void bfs(int a,int b){

    queue<int > q;
    //first -> value, second -> dist
    q.push(a);
    check[a]=make_pair(0,0);
    while(!q.empty()){
        int cur = q.front();
        int cur_t = check[cur].first;
        int t_way;
        q.pop();
        if(cur>0&&cur-1<=b+10&&check[cur-1].first==0||check[cur-1].first==cur_t+1){
            q.push(cur-1);
            t_way = check[cur-1].second;
            check[cur-1] = make_pair(cur_t+1,t_way+1);
        }
        if(cur+1<=b&&check[cur+1].first==0||check[cur+1].first==cur_t+1){
            q.push(cur+1);
            t_way = check[cur+1].second;
            check[cur+1] = make_pair(cur_t+1,t_way+1);
        }
        if(cur*2<=b+10&&check[cur*2].first==0||check[cur*2].first==cur_t+1){
            q.push(cur*2);
            t_way = check[cur*2].second;
            check[cur*2] = make_pair(cur_t+1,t_way+1);
        }
    }
    cout<<check[b].first<<"\n"<<check[b].second;
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int n,k;
    
    cin>>n>>k;

    fill(check,check+100001,make_pair(0,0));
    //first = time, secnod = the number of ways
    if(n<k) bfs(n,k);
    else cout<<n-k<<"\n1";

    return 0;
}
