#include<iostream>

using namespace std;

int main(){

    int T,N,M,i,j;
    int sol[31][31]={0};

    for(i=1;i<=30;i++){
        sol[1][i] = i;
    }
    for(i=2;i<=30;i++){
        for(j=i;j<=30;j++){
            for(int k=i-1;k<=j-1;k++){
                sol[i][j] +=sol[i-1][k];
            }
        }
    }

    cin>>T;

    for(int i=0;i<T;i++){
        cin>>N;
        cin>>M;
        cout<<sol[N][M]<<endl;
    }

    return 0;
}
