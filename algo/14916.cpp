#include<iostream>

using namespace std;

int main()
{
    int n;
    
    cin>>n;
    
    int coins = 0;
    int coin_5,coin_2;
    
    coin_5 = n/5;
    
    if((n%5)%2==0){
        coin_2 = (n-coin_5*5)/2;
    }
    else{
        coin_5--;
        coin_2 = (n-coin_5*5)/2;
    }
    coins = coin_2 + coin_5;
    if(coin_5<0) coins = -1;
    
    cout<<coins;
    
    return 0;
}
