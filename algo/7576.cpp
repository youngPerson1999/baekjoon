#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>

using namespace std;
int m,n; int**d;
vector<pair<int,int> >coordi;
bool checkT(int *t[],bool *c[]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(t[i][j]==0) return true;
        }
    }
    return false;
}
void bfs(int *t[],bool *c[]){

    queue<pair<int,int> >q;
    for(int i=0;i<coordi.size();i++){
        q.push(coordi[i]);
        c[coordi[i].first][coordi[i].second] = true;
    }

    while(!q.empty()){
        pair<int,int> cur = q.front();
        int x = cur.first; int y = cur.second;
        q.pop();
        if(x>0&&!c[x-1][y]&&t[x-1][y]==0){
            q.push(make_pair(x-1,y)); c[x-1][y] = true; t[x-1][y] = 1; 
            if(d[x-1][y]==0) d[x-1][y] = d[x][y]+1;
            else if(d[x-1][y]>0) d[x-1][y] = d[x-1][y]<d[x][y]+1?d[x-1][y]:d[x][y]+1;
        }
        if(x<m-1&&!c[x+1][y]&&t[x+1][y]==0){
            q.push(make_pair(x+1,y)); c[x+1][y] = true; t[x+1][y] = 1; 
            if(d[x+1][y]==0) d[x+1][y] = d[x][y]+1;
            else if(d[x+1][y]>0) d[x+1][y] = d[x+1][y]<d[x][y]+1?d[x+1][y]:d[x][y]+1;
        }
        if(y>0&&!c[x][y-1]&&t[x][y-1]==0){
            q.push(make_pair(x,y-1)); c[x][y-1] = true; t[x][y-1] = 1; 
            if(d[x][y-1]==0) d[x][y-1] = d[x][y]+1;
            else if(d[x][y-1]>0) d[x][y-1] = d[x][y-1]<d[x][y]+1?d[x][y-1]:d[x][y]+1;
        }
        if(y<n-1&&!c[x][y+1]&&t[x][y+1]==0){
            q.push(make_pair(x,y+1)); c[x][y+1] = true; t[x][y+1] = 1; 
            if(d[x][y+1]==0) d[x][y+1] = d[x][y]+1;
            else if(d[x][y+1]>0) d[x][y+1] = d[x][y+1]<d[x][y]+1?d[x][y+1]:d[x][y]+1;
        }
    }    
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int i,j,n_to;
    cin>>n>>m;
    int **tomato = new int*[m];
    int **tmp = new int*[m];
    bool **check = new bool*[m];
    d = new int*[m];
    

    for(i=0;i<m;i++){
        tomato[i] = new int[n];
        check[i] = new bool[n];
        tmp[i] = new int[n];
        d[i] = new int[n];
        fill(check[i],check[i]+n,false);
        for(j=0;j<n;j++){
            cin>>tomato[i][j];
            if(tomato[i][j]>0) {
                d[i][j] = 0; coordi.push_back(make_pair(i,j));
            }
            else if(tomato[i][j]==0) d[i][j]=0;
            else d[i][j] = -1;
        }
    }
    
    bfs(tomato,check);        
    
    if(checkT(tomato,check)) cout<<-1;
    else{
        int max = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) {
                if(d[i][j]>max) max = d[i][j];
            }
        }
        cout<<max;
    }
    return 0;
}
