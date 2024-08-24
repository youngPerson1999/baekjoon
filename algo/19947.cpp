#include <iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int h,y;
    
    cin>>h>>y;
    
    double *money = new double[y+1];
    money[0] = (double)h;
    for(int i=1;i<=y;i++){
        money[i] = (int)(money[i-1]*1.05);
        if(i>=3){
            money[i] = (double)max((int)money[i],(int)(money[i-3]*1.2));
        }
        if(i>=5){
            money[i] = (double)max((int)money[i],(int)(money[i-5]*1.35));
        }
    }
    cout<<(int)money[y];
    return 0;
}
