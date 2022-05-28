#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 1000001

using namespace std;

int f,s,g,u,d;
bool check[MAX];
int button[MAX];

void bfs(){
    queue<int> q;
    q.push(s);
    button[s] = 0;
    check[s] = true;
    while(!q.empty()){
        int fnt = q.front();
        // cout<<fnt<<" ";
        q.pop();
        if(fnt-d>0&&!check[fnt-d]){
            q.push(fnt-d); check[fnt-d] = true; 
            if(button[fnt]+1<button[fnt-d])button[fnt-d] = button[fnt]+1;
        }
        if(fnt+u<=f&&!check[fnt+u]){
            q.push(fnt+u); check[fnt+u] = true; 
            if(button[fnt]+1<button[fnt+u])button[fnt+u] = button[fnt]+1;
        }
    }
    // cout<<"\n";
    if(button[g]==MAX){
        cout<<"use the stairs";
        return;
    }
    else{
        cout<<button[g];
        return;
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 

    cin>>f>>s>>g>>u>>d;

    fill(check,check+MAX,false);
    fill(button,button+MAX,MAX);

    bfs();
    
    return 0;
}
