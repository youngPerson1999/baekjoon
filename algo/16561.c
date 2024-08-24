#include <stdio.h>
#include <stdlib.h>

int cal(int n);

int main(){

    int n, c = 0;

    scanf("%d",&n);

    c = cal(n);

    printf("%d",c);

    return 0;
}

int cal(int n){

    if(n == 3 || n == 6 || n == 9)    return 1;

    int num[3] = {0, 0, 0};

    int tmp = n/3, w = 0;

    for(int i=1; i<tmp;i++){
        for(int j=1; j<tmp-i;j++){
            int k = tmp - i -j;
            if(i+j+k==tmp) w++; 
        }
    }
    return w;
}