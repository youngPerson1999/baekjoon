#include <iostream>
#include <string>

using namespace std;

int isJava(string in){
    int length = in.length();
    if(in[0]=='_' || in[length - 1] == '_' || isupper(in[0]))
        return -1;
    bool isJava = false;
    for (int i = 0; i < length; i++)
    {
        if(in[i]=='_')
            isJava = true;
        if(isJava && in[i] >= 'A' && in[i] <= 'Z')
            return -1;
        if (i > 0 && in[i] == '_' && in[i - 1] == '_')
            return -1;
    }
    if(isJava)
        return 1;
    return 0;
}

string change_string(string in){
    string rst = "";
    int length = in.length();
    int is_java = isJava(in);
    if (is_java == -1)
        return "Error!";
    for (int i = 0; i < length; i++)
    {
        if(in[i]=='_')
            continue;
        else if(is_java == 1 && in[i] >= 'A' && in[i] <= 'Z')
            return "Error!";
        else if (in[i] >= 'A' && in[i] <= 'Z')
        {
            rst.push_back('_');
            rst.push_back(tolower(in[i]));
        }
        else if(i>0&&in[i-1]=='_'){
            rst.push_back(toupper(in[i]));
        }
        else
            rst.push_back(in[i]);
    }
    return rst;
}

int main(){

    string input;

    cin >> input;

    cout << change_string(input) << "\n";

    return 0;
}