#include <stdio.h>
#include <string.h>

int main(){

    char str[10] = {"0"};

    scanf("%s",str);

    for(int i = 0;i<strlen(str);i++){
        int max = i;
        for(int j=i+1 ;j<strlen(str);j++){
            if(str[j]>str[max]) max = j;
        }
        int tmp = str[max];
        str[max] = str[i];
        str[i] = tmp;
    }

    printf("%s",str);

    return 0;
}