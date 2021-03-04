#include <iostream>

using namespace std;

int main()
{
    //11726 i think this problem is a type of fibonacci
    //it can be solved using fibonacci but I will solve with dynamic programming
    int n;
    
    cin>>n;
    
    int *ways = new int[n+1];
    
    if(n==1){
        cout<<1;
        return 0;
    }
    
    
    ways[0] = 1; ways[1] = 1;
    for(int i = 2;i<=n;i++) ways[i] = (ways[i-1] + ways [i-2])%10007;
    cout<<ways[n];
    

    return 0;
}
