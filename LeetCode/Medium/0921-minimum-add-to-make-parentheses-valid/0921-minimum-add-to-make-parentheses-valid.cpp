#include<stack>
class Solution {
    private:
    bool isMatches (char ch1, char ch2) {
        if (ch1==')' && ch2=='(') {
            return 1;
        }
        else {
            return 0;
        }
    }
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for (int i=0;i<s.length();i++) {
            char ch=s[i];
            if (ch=='(') {
                st.push(ch);
            }
            else {
if ((!st.empty())&&isMatches(ch,st.top())) {
    st.pop();
}
else {
    st.push(ch);
}
            }
        }
int count=0;
while (!st.empty()) {
    count++;
    st.pop();
}
return count;

    }
};