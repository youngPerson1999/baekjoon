#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sums;

int sumOfSquare(int n){
    int root = sqrt(n);
    //제곱수 -> 최소
    if(root * root == n){
        return 1;
    }
    //2,3 처리해주기
    if(n < 4){
        return n;
    }
    int min = 100000;
    for (int i = root; i > 0; i--){
        //tSum -> 1(i제곱이니까 1개) n - i*i의 갯수랑 Min이랑 비교해줌
        int tmp = i * i, tSum = 1 + sums[n - tmp];
        //min 업데이트
        if(tSum < min){
            min = tSum;
        }
    }

    return min;
}

int main(){

    int n;

    cin >> n;
    
    for (int i = 0; i <= n; i ++){
        sums.push_back(sumOfSquare(i));
    }
    cout << sums[n] << "\n";

    return 0;
}