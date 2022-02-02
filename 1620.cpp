#include<iostream>
#include<string>
#include<map>
#include<utility>


using namespace std;


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n,m,i;
    string input;
    
    map<string,int>po;
    map<int,string>rpo;

    cin>>n>>m;
    
    for(i=1;i<=n;i++){
        cin>>input;
        po.insert(make_pair(input,i));
        rpo.insert(make_pair(i,input));
    }
    for(i=0;i<m;i++){
        cin>>input;
        if(input[0]>='0'&&input[0]<='9'){
            int num = stoi(input)-1;
            if(rpo.find(num+1)!=rpo.end()){
                cout<<rpo[num+1];
            }
        }
        else{
            if(po.find(input)!=po.end()){
                cout<<po[input];
            }   
        }
        cout<<"\n";
    }
    return 0;
}
