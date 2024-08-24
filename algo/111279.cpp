#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;

int main(){
    
    priority_queue< int, vector<int>, less<int> > pq;
    
    int n;
    
    scanf("%d",&n);
    
    int tmp;
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        if(tmp>0) pq.push(tmp);
        else if(tmp == 0){
            if(pq.size()!=0){
                printf("%d",pq.top());
                pq.pop();
            }
            else printf("0");
            printf("\n");
            getchar();
        }
    }
    
    return 0;
}
