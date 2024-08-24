#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    int t;
    
    cin>>t;
    
    for(int i=0;i<t;i++){
        int x,y;
        cin>>x>>y;
        int dist = y-x;
        int close = sqrt(dist);
        if(pow(close,2)==dist) cout<<2*close-1;
        else if(dist<=pow(close,2)+close) cout<<2*close;
        else cout<<2*close+1;
        cout<<"\n";
    }
    
    return 0;
}
//호펜 핸디1 무 && 파리 핸디1 승
