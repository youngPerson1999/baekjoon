#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int m,n,h;
vector<tuple<int,int,int> >to;
int Check_Harvest(vector<vector<vector<int> > >&t,vector<vector<vector<int> > >&d){
    int max = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(t[i][j][k]==0) return -1;
                if(d[i][j][k]>max) max = d[i][j][k];
            }
        }
    }
    return max;  
}
int bfs(vector<vector<vector<int> > >&t){
    queue<tuple<int,int,int> >q;
    vector<vector<vector<int>>> day(h,vector<vector<int>>(n,vector<int>(m,0)));

    for(int i=0;i<to.size();i++) {
        q.push(to[i]);
    }

    while(!q.empty()){
        int x,y,z;
        x = get<0>(q.front()); y = get<1>(q.front()); z = get<2>(q.front());
        q.pop();
        if(x>0&&t[x-1][y][z]==0) {
            q.push(make_tuple(x-1,y,z));
            t[x-1][y][z] = 1;
            day[x-1][y][z] = day[x][y][z]+1;
        }
        if(x<h-1&&t[x+1][y][z]==0) {
            q.push(make_tuple(x+1,y,z));
            t[x+1][y][z] = 1;
            day[x+1][y][z] = day[x][y][z]+1;
        }
        if(y>0&&t[x][y-1][z]==0) {
            q.push(make_tuple(x,y-1,z));
            t[x][y-1][z] = 1;
            day[x][y-1][z] = day[x][y][z]+1;
        }
        if(y<n-1&&t[x][y+1][z]==0) {
            q.push(make_tuple(x,y+1,z));
            t[x][y+1][z] = 1;
            day[x][y+1][z] = day[x][y][z]+1;
        }
        if(z>0&&t[x][y][z-1]==0) {
            q.push(make_tuple(x,y,z-1));
            t[x][y][z-1] = 1;
            day[x][y][z-1] = day[x][y][z]+1;
        }
        if(z<m-1&&t[x][y][z+1]==0) {
            q.push(make_tuple(x,y,z+1));
            t[x][y][z+1] = 1;
            day[x][y][z+1] = day[x][y][z]+1;
        }
    }
    
    return Check_Harvest(t,day);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 

    cin>>m>>n>>h;

    vector<vector<vector<int>>> box(h,vector<vector<int>>(n,vector<int>(m)));
    //box[h][n][m]
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>box[i][j][k];
                if(box[i][j][k]==1) to.push_back(make_tuple(i,j,k));
            }
        }
    }
    cin.clear();
    cout<<bfs(box);
    
    return 0;
}
