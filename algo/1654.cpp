#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> lans;
long long length;

int check(long long key, int N);

int main()
{
    int K,N,i;
    
    cin>>K>>N;
    
    long long input;
    for(i=0;i<K;i++){
        cin>>input;
        lans.push_back(input);
    }
            
    
    long long left = 0;
    long long right = 2147483647;
    length = 0;
    
    while(left<=right){//using binary search, check the first length of lan
        
        long long mid = (left + right)/2;
        
        if(check(mid,N)==-1){
            left = mid +1;
            if(mid > length) length = mid;
        }
        else if(check(mid,N)==1)right = mid -1;  
        
    }
    
    cout<<length;
    
    return 0;
}
int check(long long key, int N){
    
    long long sum = 0;
    
    for(int i=0;i<lans.size();i++){
        sum += lans.at(i)/key;
    }
    if(sum>=N)  return -1;
    else if(sum<N)  return 1;
}
