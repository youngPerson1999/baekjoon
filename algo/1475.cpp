#include<iostream>
#include<string>

using namespace std;

int main(){
    
    string room;
    
    cin>>room;
    
    int num[10] = {0,};
    
    int leng = room.length();
    while(leng>0){
        int n = room[leng-1]-'0';
        if(n==6||n==9)num[6]++;
        else num[n]++;
        leng--;
    }
    if(num[6]%2==1) num[6] = num[6]/2+1;
    else num[6] /= 2;
    int max = 0;
    for(int i=0;i<9;i++){
        if(num[i]>max) max = num[i];
    }
    cout<<max;
    return 0;
}
