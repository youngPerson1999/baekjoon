#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<int>v;
vector<char>result;

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, k = 1;
    stack<int>s;
    cin>>n;
    v.resize(n);
    
    for(i = 0; i < n; i++){
        cin>>v[i];
    }
    for(i = 0; i< n; i++){
        while(k <= v[i]){
            s.push(k);
            k++;
            result.push_back('+');
        }
        if(!s.empty()){
            int top = s.top();
            while(top == v[i]){
                s.pop();
                result.push_back('-');
                if(s.empty())
                    break;
                top = s.top();
            }
        }
    }
    int size = result.size();
    if(k > n +1 || !s.empty()){
        cout<<"NO\n";
    }
    else{
        for(i = 0; i< size; i++)
            cout<<result[i]<<'\n';
    }
    
    return 0;
}