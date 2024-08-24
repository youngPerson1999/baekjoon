#include<iostream>

using namespace std;

int check_multiple(int n, int m){
    int i = 0;
    while(1){
        if(n%m==0){
            n/=m;
            i++;
            continue;
        }
        return i;
    }
}
int main(){
    
    int n;
    
    cin>>n;
    int max = n;
    int two = 0; int five = 0;
    for(int i=1;i<=n;i++){
        two += check_multiple(i,2);
        five += check_multiple(i,5);
    }
    int aws = two<five?two:five;
    cout<<aws;
    
    return 0;
}
