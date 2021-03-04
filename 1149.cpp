#include <iostream>

using namespace std;

const int R = 0;
const int G = 1;
const int B = 2;

int cal_min(int a, int b, int c){
    int min = a;
    
    if(min>b) min = b;
    if(min>c) min = c;
    
    return min;
}
int cal_min(int a, int b){
    return a<b ?  a : b;
}

int main()
{
    int i,sol_dp,N;
    int RGB[1000][3];
    int sol[1000][3];
    
    cin>>N;
    
    for(i=0;i<N;i++) cin>>RGB[i][R]>>RGB[i][G]>>RGB[i][B];
    
    sol[0][R] = RGB[0][R]; 
    sol[0][G] = RGB[0][G]; 
    sol[0][B] = RGB[0][B];
    
    for(i = 1; i<N; i++){
        //I think this problem use dynamic programming algorithm
        //and I implement this algorithm using for function
        sol[i][R] = cal_min(sol[i-1][G] + RGB[i][R],sol[i-1][B] + RGB[i][R]);
        sol[i][G] = cal_min(sol[i-1][R] + RGB[i][G],sol[i-1][B] + RGB[i][G]);
        sol[i][B] = cal_min(sol[i-1][G] + RGB[i][B],sol[i-1][R] + RGB[i][B]);
    }
    
    cout<<cal_min(sol[N-1][R],sol[N-1][G],sol[N-1][B]);

    return 0;
}
