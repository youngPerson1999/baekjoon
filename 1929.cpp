#include<iostream>
#include<cstdio>

int *num;

void prime(int n){
    num[1] = 0;
    for(int i=2;i*i<=n;i++){
        if(num[i] == 0) continue;
        for(int j=i*i;j<=n;j+=i) num[j] = 0;
    }
}

int main()
{
    int m,n;
    
    scanf("%d %d",&m,&n);
    
    num = new int[n+1];
    
    for(int i=1;i<=n;i++) num[i] = i;
    
    prime(n);
    
    for(int i=m;i<=n;i++) {
        if(num[i]!=0)printf("%d\n",num[i]);
    }
    
    return 0;
}
