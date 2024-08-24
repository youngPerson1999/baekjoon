#include <stdio.h>

int main(){

    char x;
    int number=0,i = 0;
    int answer = 0,check=0;

    while(1){
        scanf("%c",&x);
        if(x=='\n')  break;
        number += (x - '0');
        i++;    
    }
    if(i == 1){
        printf("%d\n",check);
        if(number % 3 == 0) printf("YES");
        else printf("NO");
        return 0;
    }
    check++;
    while(1){
        answer = 0;
        for(i = number;i > 0;i /= 10){
            answer += (i%10);
        }
        number = answer;
        check++;
        if(answer < 10) break;
    }  

    printf("%d\n",check);

    if(answer % 3 == 0) printf("YES");
    else printf("NO");

    return 0;
}