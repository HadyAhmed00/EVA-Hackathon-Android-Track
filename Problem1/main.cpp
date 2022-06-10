#include <iostream>
#include <string>
#include "stack"
using namespace std;
int main(){
    string s ;
	cin >> s;
	int sign = 1, currNo = 0, ans = 0;
    stack<int> st;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9'){
            currNo = s[i]-'0';
            while(i+1 < s.size() && (s[i+1] >= '0' && s[i+1] <= '9'))
            {
                currNo = currNo * 10L + s[i+1]-'0';
                i++;
            }
            currNo = currNo * sign;
            ans += currNo;
            sign = 1;
        }
        else if(s[i] == '-')
            sign = -1;
        else if(s[i] == '+')
            sign = 1;
        else if(s[i] == '(')
        {
            st.push(ans);
            st.push(sign);
            ans = 0;
            sign = 1;
        }
        else if(s[i] == ')')
        {
            ans = ans * st.top();
            st.pop();
            ans += st.top();
            st.pop();
        }

    }
    cout<<ans;
    return 0;
}