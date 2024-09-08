#include<iostream>

using namespace std;

int w,b; int **paper;
int check(int n, int c, int x, int y){
    int n_c=0;
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(paper[i][j]==c) n_c++;
        }
    }
    if(n_c==n*n) return 1;
    else if(n_c>0&&n_c<n*n) return 0;
    else return -1;
}
int div_con(int n, int c,int x, int y){
    // cout<<"x = "<<x<<" y = "<<y<<"\n";
    //x,y is the starting point
    int rst = 0;
    int ch = check(n,c,x,y);
    if(ch==1) return 1;
    else if(ch==0){
        rst += div_con(n/2,c,x,y);
        rst += div_con(n/2,c,x+n/2,y);
        rst += div_con(n/2,c,x,y+n/2);
        rst += div_con(n/2,c,x+n/2,y+n/2);
    }
    else return 0;
    return rst;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int n;

    cin>>n;

    paper = new int*[n];
    for(int i=0;i<n;i++){
        paper[i] = new int[n];
        for(int j=0;j<n;j++) cin>>paper[i][j];
    }
    w=0;    b=0;
    cout<<div_con(n,0,0,0)<<"\n"<<div_con(n,1,0,0); 
    //white = 0, blue = 1    

    return 0;
}