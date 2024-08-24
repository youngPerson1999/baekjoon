#include<iostream>

using namespace std;

int cal(int);
int fact(int n){
    if(n==1||n==0)    return 1;
    return n*fact(n-1);
}
int cal_fact(int a, int b, int c){
    return fact(a+b+c)/(fact(a)*fact(b)*fact(c));
}

int main(){

    int n;

    cin>>n;

    int *num = new int[n];

    for(int i=0;i<n;i++){
        cin>>num[i];
        cout<<cal(num[i])<<endl;
    }

    return 0;
}
int cal(int n){
    int tmp = 0,num_1 = n,num_2 = 0, num_3 = 0;

    while(num_3*3<=n){
        int tmp_1 = num_1;
        num_2 = 0;
        while(tmp_1+num_2+num_3*3<=n){
            tmp += cal_fact(tmp_1,num_2,num_3);
            //cout<<tmp_1<<" "<<num_2<<" "<<num_3<<endl;
            tmp_1 -= 2;
            num_2 += 1;
            if(tmp_1<0) break;
        }
        num_1 -= 3;
        if(num_1<0) break;
        num_3++;

    }
    return tmp;

}