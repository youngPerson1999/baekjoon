#include<iostream>

using namespace std;

long gcd(long a, long b){
    
    if(a<b) return gcd(a,b%a);
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(){
    
    long a,b;
    
    cin>>a>>b;
    
    long n = gcd(a,b);

    for(int i=0;i<n;i++) cout<<1;
    
    return 0;
}
