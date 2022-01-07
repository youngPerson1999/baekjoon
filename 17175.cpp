#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int>fibo(51);
    fibo[0] = fibo[1] = 1; fibo[2] = 3;
    for(int i=3;i<=50;i++){
        fibo[i] = (fibo[i-2]+fibo[i-1] +1)%1000000007;
    }
    int n;
    cin>>n;
    cout<<fibo[n];
    return 0;
}
