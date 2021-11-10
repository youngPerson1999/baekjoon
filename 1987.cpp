#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;
bool alpha[26];
char g[20][20];
int maxm,r,c;

void dfs(int y, int x, int num){
    
    if(num>maxm) maxm = num;
    if(y>r||x>c) return;
        
    if(y>0&&alpha[g[y-1][x]-'A']==false){//up
        alpha[g[y-1][x]-'A'] = true;
        dfs(y-1,x,num+1);
        alpha[g[y-1][x]-'A'] = false;
    }
    if(y<r-1&&alpha[g[y+1][x]-'A']==false){//down
        alpha[g[y+1][x]-'A'] = true;
        dfs(y+1,x,num+1);
        alpha[g[y+1][x]-'A'] = false;
    }
    if(x>0&&alpha[g[y][x-1]-'A']==false){//left
        alpha[g[y][x-1]-'A'] = true;
        dfs(y,x-1,num+1);
        alpha[g[y][x-1]-'A'] = false;
    }
    if(x<c-1&&alpha[g[y][x+1]-'A']==false){//right
        alpha[g[y][x+1]-'A'] = true;
        dfs(y,x+1,num+1);
        alpha[g[y][x+1]-'A'] = false;
    }
}
int main(){
    
    cin>>r>>c;
   
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>g[i][j];
        }
    }
    maxm = 0;
    fill(alpha,alpha+26,false);
    alpha[g[0][0]-'A'] = true;
    dfs(0,0,1);
    
    cout<<maxm;

    return 0;
}
