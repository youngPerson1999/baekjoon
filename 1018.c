#include <stdio.h>

int main(){

    int N,M;
    int i,j;
    int sol = 800,cnt_1 = 0,cnt_2 = 0;

    scanf("%d %d",&M,&N);

    char space[50][50];
    
    for(i=0;i<M;i++)
        scanf("%s",&space[i]);

    for(i=0 ; i<M-7 ; i++){
        for(j=0 ; j<N-7 ; j++){
            cnt_1 = 0;
            cnt_2 = 0;
            for(int k=i ; k<i+8 ; k++){
                for(int l=j ; l<j+8 ; l++){
                    if((k+l)%2 == 0){
                        if(space[k][l] =='B')   cnt_1++;
                        else                    cnt_2++; 
                    }
                    else{
                        if(space[k][l] =='W')   cnt_1++;
                        else                    cnt_2++;
                    }
                }
            }
            sol = sol < cnt_1 ? sol : cnt_1;
            sol = sol < cnt_2 ? sol : cnt_2;    
        }
    }

    printf("%d\n",sol);

    return 0;
}
