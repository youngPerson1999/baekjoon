#include<iostream>
#include<string>

using namespace std;

string pString(string a, string b){
    //b>a
    if(b.length()<a.length()) swap(a,b);
    int lb = b.length();
    int la = a.length();
    int lt = lb+1;
    string t;
    t.resize(lt);
    for(int i=0;i<lb;i++)t[i] = '0';
    for(int i=0;i<lb;i++){
        int ta,tb,ts;
        if(i<la) ta = a[i]-'0';
        else ta = 0;
        tb = b[i]-'0';
        ts = ta+tb;
        if(t[i]=='1') ts++;
        if(ts>=10) t[i+1]='1';
        t[i] = '0'+ts%10;
    }
    if(t[lt-1]<='0'||t[lt-1]>'9') t.resize(lt-1);
    t.shrink_to_fit();

    return t;
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int n,m,i;
    
    cin>>n>>m;
    
    string **combi = new string*[n+1];
    combi[1] = new string[2];
    combi[1][0] = combi[1][1] = "1";
    for(i=2;i<=n;i++){
        combi[i] = new string[i+1];
        combi[i][0] = combi[i][i] = "1";
        // cout<<i<<"= ";
        for(int j=1;j<i;j++){
            combi[i][j] = pString(combi[i-1][j-1],combi[i-1][j]);
            // cout<<combi[i][j]<<"  ";
        }
        //delete combi[i-1];
        // cout<<"\n";
    }
    string ans = combi[n][m];
    for(i=ans.length()-1;i>=0;i--) cout<<ans[i];

    return 0;
}
