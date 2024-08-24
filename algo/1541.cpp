#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    
    cin>>input;
    
    int sol = 0;    //solution of problem
    int parsing = 0;  //if parsing existed, 1 or 0
    int tmp_num = 0;
    int tmp_sum = 0;
    
    for(int i=0;i<input.length();i++){
        char argu = input.at(i);
        if(argu=='+'){
            tmp_sum += tmp_num;
            tmp_num = 0;
        }
        else if(argu=='-'){
            if(parsing == 1){
                tmp_sum += tmp_num;
                sol -= tmp_sum;
                tmp_num = 0;
                tmp_sum = 0;
                parsing = 1;
            }
            else{
                tmp_sum += tmp_num;
                sol += tmp_sum;
                tmp_num = 0;
                tmp_sum = 0;
                parsing = 1;
            }
        }
        else{   //number
            tmp_num *= 10;
            tmp_num += argu-'0';
        }
        if(i==input.length()-1){
            if(parsing==1){
                tmp_sum += tmp_num;
                sol -= tmp_sum;
            }
            else{
                tmp_sum += tmp_num;
                sol += tmp_sum;
            }
            break;
        }
    }
    
    cout<<sol;
    
    return 0;
}
