#include<iostream>
#include<cstdlib>

using namespace std;

void paint_area(int, int, int[][101]);

int main(){
    
    int N,i,j;

    cin>>N;

    int paper[101][101] = { 0 };
    int **xy = new int*[N];
    for(i=0;i<N;i++){
        xy[i] = new int[2];
    }

    for(i=0;i<N;i++){
        for(j=0;j<2;j++){
            cin>>xy[i][j];
        }
    }

    int area_sum = 0;

    for(i=0;i<N;i++){
        paint_area(xy[i][0],xy[i][1],paper);
    }

    for(i=0;i<=100;i++){
        for(j=0;j<=100;j++){
            if(paper[i][j] >= 1)    area_sum++;
        }
    }

    cout<<area_sum;

    return 0;
}
void paint_area(int x, int y, int paper[101][101]){
    for(int i=x;i<x+10;i++){
        for(int j=y;j<y+10;j++){
            paper[i][j]++;
        }
    }
}
