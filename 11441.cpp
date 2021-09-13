#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;


int main(){
    
    int n,m,i;
    
    scanf("%d",&n);

    vector<int>sum;
    sum.push_back(0);
    
    for(i=1;i<=n;i++) {
        int a;
        scanf("%d",&a);
        sum.push_back(a+sum[i-1]);
    }
    
    scanf("%d",&m);
    
    for(i=0;i<m;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",sum[b]-sum[a-1]);
    }
    
    
    return 0;
}
