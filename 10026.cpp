#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;
bool **check;
char **map;
pair<int,int> next_index(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(check[i][j]==false) return make_pair(i,j);
        }
    }
    return make_pair(-1,-1);
}
int mapping(int n){
    queue<pair<int,int> > q;
    int terr = 0;
    int cnt=0;
    while(cnt<n*n){
        pair<int,int> next = next_index(n);
        //cout<<next.first<<", "<<next.second<<"\n";
        q.push(next);
        check[next.first][next.second] = true;
        char color = map[next.first][next.second];
        while(!q.empty()){
            pair<int,int> curr = q.front();
            int x = curr.first; int y = curr.second;
            q.pop();
            cnt++;
            if(x>0&&!check[x-1][y]&&map[x-1][y]==color){   //up
                q.push(make_pair(x-1,y)); check[x-1][y] = true;
            }
            if(x<n-1&&!check[x+1][y]&&map[x+1][y]==color){   //down
                q.push(make_pair(x+1,y)); check[x+1][y] = true;
            }
            if(y>0&&!check[x][y-1]&&map[x][y-1]==color){   //left
                q.push(make_pair(x,y-1)); check[x][y-1] = true;
            }
            if(y<n-1&&!check[x][y+1]&&map[x][y+1]==color){   //right
                q.push(make_pair(x,y+1)); check[x][y+1] = true;
            }
        }
        terr++;
    }
    
    return terr;
}
void abnormal(bool check[], char map[]){
    
}
int main(){
    int n;
    
    cin>>n;
    
    
    check = new bool*[n];
    map = new char*[n];
    
    for(int i=0;i<n;i++){
        check[i] = new bool[n];
        map[i] = new char[n];
        for(int j=0;j<n;j++){
            char color;
            cin>>color;
            map[i][j] = color;
        }
    }
    
    for(int i=0;i<n;i++)fill(check[i],check[i]+n,false);
    cout<<mapping(n)<<" ";
    for(int i=0;i<n;i++)fill(check[i],check[i]+n,false);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            if(map[i][j]=='G') map[i][j]='R';
        }
    }
    cout<<mapping(n);
    return 0;
}
