#include<iostream>

using namespace std;

int main(){

    int N,K,i,j;

    cin>>N>>K;
    
    int *array = new int[N*K+1];

    for(i=1;i<=N;i++){
        array[i] = i;
    }
    for(i=N+1;i<=N*K;i++){
        array[i] = 0;
    }

    cout<<"<";

    i=0;    int tmp = N,check = 0,count = N,s=N;

    while(N>0){
        i++;
        count--;
        if(i==s*K){
            cout<<array[i]<<">";
            break;
        }
        if(i % K == 0){  
            cout<<array[i]<<", ";
            array[i] = 0;
            tmp--;
            check++;  
            //cout<<endl;
        }
        else{
            array[i+N-check] = array[i];
        }
        if(count == 0){
            N=tmp;
            count = N;
            check = 0;
        }
        /*for(int k=1;k<s*K;k++)
            cout<<array[k]<<" ";
        cout<<endl;*/
    }

    delete[] array;

    return 0;
}
