/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4889                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4889                           #+#        #+#      #+#    */
/*   Solved: 2025/03/18 20:54:36 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool check_loop(string str) {
    int l = str.length();
    for (int i = 0; i < l; i++)
        if(str[i]== '-')
            return false;
    return true;
}

int cal_opt(string str) {
    stack<char> st;
    int o = 0, len = str.length();
    for (int i = 0; i < len; i++)
    {
        if(str[i] == '{')
            st.push('{');
        else
        {
            if(!st.empty())
                st.pop();
            else
            {
                o++;
                st.push('{');
            }
        }
    }
    return o + st.size() / 2;
}

int main () {
    
    string str;
    int i = 0;
    while(1) {
        i++;
        cin >> str;
        if(!check_loop(str))
            break;
        cout << i << ". " << cal_opt(str) << '\n';
    } 

    return 0;
}