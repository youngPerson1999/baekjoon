#include<iostream>
#include<string>

using namespace std;

int main(){

    string input;

    cin>>input;

    if(input[0]=='0'){
        cout<<"0";
        return 0;
    }

    int *octal = new int[(input.length()-1)/3+1];
    int i,index=0;

    for(i=input.length()-1;i>=0;i--,index++){
        if(index%3==0){
            octal[index/3] = (input[i]-'0');
        }
        else if(index%3==1){
            octal[index/3] += 2*(input[i]-'0');
        }
        else{
            octal[index/3] += 4*(input[i]-'0');
        }
    }
    
    index--;
    for(i=index/3;i>=0;i--){
        cout<<octal[i];
    }

    return 0;
}
