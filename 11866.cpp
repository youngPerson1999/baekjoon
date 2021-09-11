#include<iostream>
#include<queue>

using namespace std;

int main(){
    
    queue<int> josep;
    
    int n,k;
    
    cin>>n>>k;
    
    for(int i=1;i<=n;i++) josep.push(i);
    
    cout<<"<";
    int tmp_k=1;
    while(!josep.empty()){
        if(tmp_k<k){
            josep.push(josep.front());
            josep.pop();
            tmp_k++;
        }
        else{   //tmp_k==k
            cout<<josep.front();
            josep.pop();
            if(!josep.empty()) cout<<", ";
            tmp_k = 1;
        }
    }
    cout<<">";
    
    return 0;
}
