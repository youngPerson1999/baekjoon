#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
vector<int>per;
void swap(int &a,int &b){
    int tmp = a;
    a=b;
    b=tmp;
}
void n_m(int depth, int n, int m, int l[]){
    if(depth==m){
        int tmp = 0;
        for(int i=0;i<m;i++) {
            tmp += l[i];
            tmp*=10;
        }
        tmp/=10;
        per.push_back(tmp);
        return;
    }
    for(int i=depth;i<n;i++){
        swap(l[depth],l[i]);
        n_m(depth+1,n,m,l);
        swap(l[depth],l[i]);
    }
}

int main(){
    
    int n,m;
    
    cin>>n>>m;
    int list[n];
    for(int i=0;i<n;i++) list[i] = i+1;
    n_m(0,n,m,list);
    sort(per.begin(),per.end());
    for(int i=0;i<per.size();i++){
        int k = pow(10,m-1);
        for(int j=0;j<m;j++) {
            cout<<(per[i]/k)%10<<" ";
            k /=10;
        }
        cout<<"\n";
    }
    
    return 0;
}
