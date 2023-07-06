#include <iostream>

using namespace std;

int findNum(int n, int num){
    int cnt = 0;   
    while (n > 0){
        n /= num;
        cnt += n;
    }
    return cnt;
}

int main(){

    int n,m;

    cin>>n>>m;

    int k = n - m;

    //n, m, k
    int five[3];    
    int two[3];
    five[0] = findNum(n, 5);
    two[0] = findNum(n, 2);
    five[1] = findNum(m, 5);
    two[1] = findNum(m, 2);
    five[2] = findNum(k, 5);
    two[2] = findNum(k, 2);

    int f = five[0] - five[1] - five[2], t = two[0] - two[1] - two[2];

    cout<<(f < t ? f : t);

    return 0;
}