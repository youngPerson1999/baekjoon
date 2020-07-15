#include<iostream>
#include<string>

using namespace std;

int main(){

    string input;

    cin>>input;

    int words = 0,n = input.length();

    for(int i=0;i<n;i++){
        char f, s, t;

        if(i+1<n){
            f = input[i], s = input[i+1];
            if(f == 'c'&&s=='='||s=='-')i++;
            else if(f == 'd'&&s=='-')   i++;
            else if(f=='l'&&s=='j') i++;
            else if(f=='n'&&s=='j') i++;
            else if(f=='s'&&s=='=') i++;
            else if(f=='z'&&s=='=') i++;
            if(i+2<n){
                t = input[i+2];
                if(f=='d'&&s=='z'&&t=='=')  i += 2;
            }
        }
        
        words++;
    }

    cout<<words;
    return 0;
}
