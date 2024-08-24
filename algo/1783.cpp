#include <iostream>

using namespace std;

int way_1(int n, int m);   //up 2, right 1
int way_2(int n, int m);   //up 1, right 2
int way_3(int n, int m);   //down 1, right 2
int way_4(int n, int m);   //down 2, right 1

int k_n = 1;    //k_n = the vertical position of knight 
int k_m = 1;   //k_m = the horizontal position of knight

int main()
{
    int n,m;
    
    cin>>n>>m;
    
    int visited = 1;    //the visited location in chessboard
    
    if(n<3){    //only way_2,3
        while(1){
            if(way_2(n,m)==1||way_3(n,m)==1){
                visited++;
            }
            else{
                if(visited<5){
                    cout<<visited;
                    return 0;
                }
                else cout<<4;
                return 0;
            }
        }
    }
    if(m<7){
        while(1){
            if(way_1(n,m)==1||way_4(n,m)==1){
                visited++;
            }
            else{
                if(visited<5){
                    cout<<visited;
                    return 0;
                }
                else cout<<4;
                return 0;
            }
        }
    }
    if(way_2(n,m)==1) visited++;
    if(way_3(n,m)==1) visited++;
    
    visited += m-k_m;
    
    cout<<visited;
    
    return 0;
}
int way_1(int n, int m){
    if(n<k_n+2 || m<k_m+1) return 0;
    k_n += 2; k_m ++;
    return 1;
}
int way_2(int n, int m){
    if(n<k_n+1 || m<k_m+2) return 0;
    k_m += 2; k_n ++;
    return 1;
}
int way_3(int n, int m){
    if(k_n<2 || m<k_m+2) return 0;
    k_m += 2; k_n--;
    return 1;
}
int way_4(int n, int m){
    if(k_n<3 || m<k_m+1) return 0;
    k_n -= 2; k_m ++;
    return 1;
}
