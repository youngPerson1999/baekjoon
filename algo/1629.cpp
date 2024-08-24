#include<iostream>
#include<cmath>

using namespace std;
long long multiple(int a,int b,int c){
    if(b==1)    return a%c;
    else if(b%2==0){
        long long k = multiple(a,b/2,c)%c;
        return k*k%c;
    }
    else if(b%2==1){
        long long k = multiple(a,(b-1)/2,c)%c;
        return (((a%c)*k)%c*k)%c;
    }
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int a,b,c;
    cin>>a>>b>>c;
    
    cout<<multiple(a,b,c);
    
    return 0;
}
