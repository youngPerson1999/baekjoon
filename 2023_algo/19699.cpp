#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector<int>prime;

int* findPrime(int size){
    int *num = new int[size + 1];
    for(int i = 0; i<= size; i++)
        num[i] = 1;
    num[0] = 0, num[1] = 0; 
    for(int i = 2; i <= size ; i++){
        if(num[i]==0) continue;
        for(int j = 2*i ; j <= size; j += i)
            num[j] = 0;
    }
    return num;
}

void combination(int idx, int r, int*num, vector<int>cow, int sum){
    if (r==m){
        if( sum % 2 != 0 || sum == 2) {
            if (num[sum] > 0){
                prime.push_back(sum);
                num[sum] = 0;
            }
        }
    }
    for(int i = idx ; i < n; i++){
        sum += cow[i];
        combination(i + 1, r + 1, num, cow, sum);
        sum -= cow[i];
    }
}

void solve(int n, int m, vector<int>cow){
    int big = 0;
    for(int i = 1 ; i <= m; i ++){
        big += cow[n - i];
    }

    int *num = findPrime(big);

    combination(0, 0, num, cow, 0); 
}

int main(){

    cin>>n>>m;

    vector <int> cow(n);
    for(int i = 0; i < n; i++){
        cin>>cow[i];
    }
    sort(cow.begin(), cow.end());
    
    solve(n, m, cow);
    sort(prime.begin(), prime.end());

    int size = prime.size();
    if(size == 0) cout<<"-1\n";
    else
        for(int i = 0 ; i< size; i++){
            cout<<prime[i];
            if(i < size-1) cout<<" ";
            else cout<<"\n";
        }
    return 0;

}