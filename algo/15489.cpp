#include<iostream>

using namespace std;

int main()
{
    int R,C,W;
    
    cin>>R>>C>>W;
    
    int **pascal = new int*[R+W-1];
    for(int i=0;i<R+W-1;i++){
        pascal[i] = new int[i+1];
        pascal[i][0] = 1;
        pascal[i][i] = 1;
        if(i>=2){
            for(int j=1;j<=i-1;j++){
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
    }
    
    int sum = 0;
    
    for(int i=0;i<W;i++){
        for(int j = 0;j<=i;j++){
            sum += pascal[i+R-1][j+C-1];
        }
    }
    
    
    cout<<sum;
    
    return 0;
}
