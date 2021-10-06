#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    
    int n;
    
    scanf("%d",&n);
    
    vector<int> num;
    double sum = 0;
    int cnt[8001];
    fill(cnt,cnt+8002,0);
    int mf = 0;     //max frequency
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        num.push_back(tmp);
        cnt[tmp+4000]++;
        if(cnt[tmp+4000]>mf) mf = cnt[tmp+4000];
        sum += (double)tmp;
    }
    
    sort(num.begin(),num.end());
    int ave = round((double)sum/n);
    printf("%d\n",ave);
    
    int mid;
    mid = num[(n-1)/2];
    printf("%d\n",mid);
    
    int mfnum;
    bool chSecond = false;
    if(n==1){
        printf("%d",num[0]);
    }
    else{
        if(mf==1) printf("%d",num[1]);
        else{
            for(int i=0;i<8001;i++){
                if(cnt[i]==mf) {
                    mfnum = i-4000;
                    if(chSecond) break;
                    chSecond = true;
                }
            }
            printf("%d",mfnum);
        }
    }
    
    printf("\n%d\n",num.back()-num.front());
    return 0;
}
