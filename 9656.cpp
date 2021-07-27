#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    
    cin>>n;
    
    int *sol = new int[n+1];
    
    //0 means CY, 1 means SK
    sol[1] = 0;
    sol[2] = 1;
    sol[3] = 0;
    for(int i=4;i<=n;i++){
        if(min(sol[i-1],sol[i-3])==1){
            sol[i]=0;
        }
        else sol[i] = 1;
    }
    
    if(sol[n]==0) cout<<"CY";
    else          cout<<"SK";
    
    return 0;
}
