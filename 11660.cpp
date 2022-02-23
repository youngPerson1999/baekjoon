#include<iostream>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int n,m,i,j,t,x1,y1,x2,y2,sum;

    cin>>n>>m;
    int **nn = new int*[n];

    for(i=0;i<n;i++){
        nn[i] = new int[n];
        cin>>nn[i][0];
        for(j=1;j<n;j++){
            cin>>t;
            nn[i][j] = t+nn[i][j-1];
        }
    }
    for(i=0;i<m;i++){
        int sum=0;
        cin>>x1>>y1>>x2>>y2;
        for(j=x1-1;j<x2;j++){
            int partsum = 0;
            if(y1==1) partsum = nn[j][y2-1];
            else partsum = nn[j][y2-1]-nn[j][y1-2];
            sum+=partsum;
        }
        cout<<sum<<"\n";
    }

    return 0;
}
