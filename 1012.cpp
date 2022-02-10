#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
pair<int,int>findXY(int *f[], bool *c[],int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(f[i][j]>0&&!c[i][j]) return make_pair(i,j); 
        }
    }
    return make_pair(-1,-1);
}
void bfs(int *f[],bool *c[],pair<int,int>idx,int m, int n){
    //x, y == starting point
    queue<pair<int,int> >q;
    q.push(idx);
    c[idx.first][idx.second] = true;
    while(!q.empty()){
        pair<int,int> curr = q.front();
        int x = curr.first; int y = curr.second;
        q.pop();
        if(x>0&&!c[x-1][y]&&f[x-1][y]>0){
            q.push(make_pair(x-1,y)); c[x-1][y] = true;
        }
        if(x<m-1&&!c[x+1][y]&&f[x+1][y]>0){
            q.push(make_pair(x+1,y)); c[x+1][y] = true;
        }
        if(y>0&&!c[x][y-1]&&f[x][y-1]>0){
            q.push(make_pair(x,y-1)); c[x][y-1] = true;
        }
        if(y<n-1&&!c[x][y+1]&&f[x][y+1]>0){
            q.push(make_pair(x,y+1)); c[x][y+1] = true;
        }
    }

}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int t,m,n,k,x,y;
    cin>>t;
    for(int a=0;a<t;a++){
        cin>>m>>n>>k;
        int **field  = new int*[m];
        bool **check = new bool*[m];
        for(int i=0;i<m;i++){
            field[i] = new int[n];
            check[i] = new bool[n];
            fill(field[i],field[i]+n,0);
            fill(check[i],check[i]+n,false);
        }
        for(int i=0;i<k;i++){
            cin>>x>>y;
            field[x][y] = 1;
        }
        pair<int,int>nextidx = findXY(field,check,m,n);
        int num = 1;
        while(nextidx.first!=-1){
            bfs(field,check,nextidx,m,n);
            nextidx = findXY(field,check,m,n);
            if(nextidx.first!=-1) num++;
        }
        cout<<num<<"\n";
    }
    return 0;
}
