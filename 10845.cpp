#include<iostream>
#include<string>
#include<cstdio>
#include<sstream>

using namespace std;

int main(){

    int n,x;

    cin>>n;
    getchar();

    int *queue = new int[n];
    int size = 0;
    for(int i=0;i<n;i++)
        queue[i] = 0;

    for(int i=0; i<n;i++){
        string input;
        getline(cin,input);

        if(input == "pop"){
             if(size==0){ 
                cout<<"-1";
            }
            else{
                size--;
                cout<<queue[0];
                for(int j=1;j<=size;j++){
                    queue[j-1] = queue[j];
                }
            }
        }
        else if(input == "size") cout<<size;
        else if(input == "empty"){
            if(size==0) cout<<"1";
            else    cout<<"0";
        }
        else if(input == "front"){
            if(size == 0)   cout<<"-1";
            else cout<<queue[0];
        }
        else if(input == "back"){
            if(size == 0)   cout<<"-1";
            else cout<<queue[size-1];
        }
        else{   //push
            istringstream iss(input);
            string tmp;
            iss>>tmp;
            iss>>tmp;
            x = stoi(tmp);
            queue[size] = x;
            size++;
            continue;
        }
    
        cout<<"\n";

    }

    delete[] queue;
    
    return 0;
}