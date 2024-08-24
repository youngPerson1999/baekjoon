#include<iostream>
#include<string>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    string a,b;
    
    cin>>a>>b;
    
    if(a.length()==b.length()){
        int diff = 0;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]) diff++;
        }
        cout<<diff;
    }
    else{
        int l = a.length();
        int k = b.length()-l;
        int min = l;
        for(int i=0;i<=k;i++){
            int diff = 0;
            for(int j=0;j<l;j++){
                if(a[j]!=b[i+j]) diff++;
            }
            if(diff<min) min = diff;
        }
        cout<<min;
    }
    
    return 0;
}
