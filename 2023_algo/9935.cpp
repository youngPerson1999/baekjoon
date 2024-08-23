#include <iostream>
#include <string>

using namespace std;

string frula, input;
int f_length, i_length, t_length;

void sol()
{
    string t = "";
    for (int i = 0; i < i_length; i++)
    {
        //일종의 stack느낌
        t += input[i];
        t_length = t.length();
        //마지막이 같을때 돌려주기.
        if (t_length >= f_length && t[t_length - 1] == frula[f_length - 1])
        {
            bool flag = false;
            for (int j = 0; j < f_length; j++)
            {
                //frula랑 다르면 자르면 안됨
                if(t[t_length - f_length + j] != frula[j])
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                t.resize(t_length - f_length);
            }
        }
    }
    if (t.length() == 0)
        cout << "FRULA\n";
    else
        cout << t << "\n";
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> input >> frula;
    f_length = frula.length();
    i_length = input.length();
    sol();
    return 0;
}