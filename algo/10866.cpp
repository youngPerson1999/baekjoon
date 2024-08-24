#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdio>

using namespace std;

vector<int>dq;

void push_front(int);
void pop_front();

int main(){

    int n;

    cin>>n;
    getchar();

    for(int i=0;i<n;i++){
        string in;
        getline(cin,in);

        if(in=="size"){
            cout<<dq.size();
        }
        else if(in=="empty"){
            if(dq.empty()) cout<<"1";
            else    cout<<"0";
        }
        else if(in=="front"){
            if(!dq.empty()) cout<<dq.front();
            else    cout<<"-1";
        }
        else if(in=="back"){
            if(!dq.empty()) cout<<dq.back();
            else    cout<<"-1";
        }
        else if(in=="pop_front"){
            if(dq.empty()) cout<<"-1";
            else {
                cout<<dq.front();
                pop_front();
            }
        }
        else if(in=="pop_back"){
            if(dq.empty()) cout<<"-1";
            else{
                cout<<dq.back();
                dq.pop_back();
            }
        }
        else{       //push
            istringstream iss(in);
            string tmp;
            int x;            
            iss>>tmp;
            iss>>x;

            if(tmp=="push_back"){
                dq.push_back(x);
            }
            else if(tmp=="push_front"){
                push_front(x);
            }
            continue;
        }
        cout<<"\n";
    }    

    return 0;
}
void push_front(int x){
    vector<int>tmp;
    tmp.push_back(x);
    for(int i=0;i<dq.size();i++){
        tmp.push_back(dq.at(i));
    }
    dq.swap(tmp);
}
void pop_front(){
    vector<int>tmp;
    for(int i=1;i<dq.size();i++){
        tmp.push_back(dq.at(i));
    }
    dq.swap(tmp);
}