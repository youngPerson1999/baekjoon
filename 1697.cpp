#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int seek(int n,int k){
    queue<int> q;
    bool check[100001];
    fill(check,check+100001,false);
    
    q.push(n);
    check[n] = true;
    int seek_time = 0;
    
    while(!q.empty()){
        int size = q.size();    //it means the level of graph
        for(int i=0;i<size;i++){
            int curr = q.front();
            if(curr==k) return seek_time;
            q.pop();
            if(curr>0&&curr-1<=100000&&check[curr-1]==false) {
                q.push(curr-1);    check[curr-1] = true;  
            }
            if(curr+1<=100000&&check[curr+1]==false) {
                q.push(curr+1);    check[curr+1] = true;  
            }
            if(curr*2<=100000&&check[curr*2]==false) {
                q.push(2*curr);    check[curr*2] = true;  
            }
        }
        seek_time++;
    }
    
    return seek_time;
}

int main(){
    
    int n,k;
    
    cin>>n>>k;
    
    cout<<seek(n,k);
    
    return 0;
}
