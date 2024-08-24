#include<iostream>

using namespace std;

int main(){

    int a,b;

    cin>>a>>b;

    int GCD=1;
    int LCM = a*b;

    int min  = a<b?a:b;

    for(int i = min; i>=2;i--){
        if(a%i==0 && b%i==0){    
            GCD *= i;
            a /= i;
            b /= i;
        }
    }

    LCM /= GCD;

    cout<<GCD<<endl<<LCM;

    return 0;
}
