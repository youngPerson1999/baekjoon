#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>

using namespace std;

int main(){

    int n;

    cin>>n;
    getchar();
    
    int*virus = new int[n+1];
    vector<int> adj[101];

    for(int i=1;i<=n;i++){
        if(i==1) virus[i] = 1;
        else virus[i] = 0;
    }

    int m,x,y;

    cin>>m;

    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    queue<int>q;

    q.push(1);

    while(!q.empty()){

        int node = q.front();
        q.pop();

        for(int i=0;i<adj[node].size();i++){
            int next = adj[node][i];
            if(virus[next]==0){
                virus[next] = 1;
                q.push(next);
            }
        }
    }

    int sum = -1;

    for(int i=1;i<=n;i++){       
        if(virus[i]==1) sum++;
    }   

    cout<<sum;

    return 0;
}
