#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<utility>

using namespace std;
int n,m;
int bfs(vector<vector<int> >mi,vector<vector<int> >t){
    vector<vector<bool> >c(n,vector<bool>(m,false));
    queue<pair<int,int> >q;
    q.push(make_pair(0,0));
    c[0][0] = true;
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // cout<<x<<", "<<y<<"\n";
        if(x>0&&t[x-1][y]>=0&&!c[x-1][y]){
            q.push(make_pair(x-1,y));
            c[x-1][y] = true;
            t[x-1][y] = t[x][y]+1;
        }
        if(x<n-1&&t[x+1][y]>=0&&!c[x+1][y]){
            q.push(make_pair(x+1,y));
            c[x+1][y] = true;
            t[x+1][y] = t[x][y]+1;
        }
        if(y>0&&t[x][y-1]>=0&&!c[x][y-1]){
            q.push(make_pair(x,y-1));
            c[x][y-1] = true;
            t[x][y-1] = t[x][y]+1;
        }
        if(y<m-1&&t[x][y+1]>=0&&!c[x][y+1]){
            q.push(make_pair(x,y+1));
            c[x][y+1] = true;
            t[x][y+1] = t[x][y]+1;
        }
    }
    return t[n-1][m-1];

}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>n>>m;

    vector<vector<int> >miro(n,vector<int>(m,0));
    vector<vector<int> >time(n,vector<int>(m,1));
    for(int i=0;i<n;i++){
        string in;
        cin>>in;
        for(int j=0;j<m;j++) {
            miro[i][j] = in[j]-'0';
            if(miro[i][j]==0) time[i][j] = -1;
        }
    }
    cout<<bfs(miro,time);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++) cout<<time[i][j]<<" ";
    //     cout<<"\n";
    // }
    // cout<<time[n-1][m-1];


    return 0;
}
