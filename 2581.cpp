#include<iostream>

using namespace std;

int eratos(int);

int main(){

    int n,m;

    cin>>n;
    cin>>m;

    int sum = 0,cnt = 0,min;

    for(int i=n;i<=m;i++){
        int tmp = eratos(i);
        if(tmp != 0){
            if(cnt==0)  min = tmp;
            sum += tmp;
            cnt++;
        }
    }
    if(sum==0)  {
        cout<<"-1";
        return 0;
    }
    cout<<sum<<endl<<min;

    return 0;
}
int eratos(int n){
    if(n<=1)    return 0;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0) return 0;
    }
    return n;
}