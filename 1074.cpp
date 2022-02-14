#include<iostream>
#include<cmath>

using namespace std;

int r,c,n;
int rr[16];

int findZ(int c, int r, int i, int l,int x, int y){
    if(i==1){
        if(c%2==0&&r%2==0) return l;
        if(c%2==1&&r%2==0) return l+1;
        if(c%2==0&&r%2==1) return l+2;
        if(c%2==1&&r%2==1) return l+3;
    }
    //quadrant 1,2,3,4
    int k = pow(2,i);
    int w = (k*k)/4;
    if(c<x+(k/2)&&r<y+(k/2)){   //1
        return findZ(c,r,i-1,l,x,y);
    }
    if(c>=x+(k/2)&&r<y+(k/2)){  //2
        return findZ(c,r,i-1,l+w,x+k/2,y);
    }
    if(c<x+(k/2)&&r>=y+(k/2)){  //3
        return findZ(c,r,i-1,l+w*2,x,y+k/2);
    }
    if(c>=x+(k/2)&&r>=y+(k/2)){ //4
        return findZ(c,r,i-1,l+w*3,x+k/2,y+k/2);
    }
    return -1;
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    for(int i=0;i<=15;i++) rr[i] = pow(2,i);
    
    cin>>n>>r>>c;
    int max = r>c?r:c;
    for(int i=1;i<=15;i++){
        if(max<rr[i]){
            n = i; break;
        }
    }
 
    cout<<findZ(c,r,n,0,0,0);

    return 0;
}
