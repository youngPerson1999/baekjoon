#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;


int main(){

    int n,i,j,r,x1,x2,y1,y2,r1,r2;

    cin>>n;

    for(i=0;i<n;i++){
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        r = pow((x2-x1),2) + pow((y2-y1),2);
        int sum_r = pow((r1+r2),2);
        int sub_r = pow((r2-r1),2);
        if(r==0&&r1==r2)    cout<<"-1";
        else if(r>pow((r1+r2),2))   cout<<"0";
        else if(r==(r1+r2)*(r1+r2))   cout<<"1";
        else if(r<(r1+r2)*(r1+r2)&&r>(r2-r1)*(r2-r1))   cout<<"2";
        else if(r==(r2-r1)*(r2-r1)) cout<<"1";
        else if(r<(r2-r1)*(r2-r1))  cout<<"0";
        cout<<endl;
        getchar();
    }

    return 0;
}