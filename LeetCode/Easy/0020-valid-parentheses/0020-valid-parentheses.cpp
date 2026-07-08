#include <stack>

class Solution {
private:
    bool isMatches(char ch1, char ch2) {
        if ((ch1 == ')' && ch2 == '(') || (ch1 == '}' && ch2 == '{') || (ch1 == ']' && ch2 == '[')) {
            return true;
        }
        return false;
    }

public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if ((!st.empty()) && isMatches(ch, st.top())) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};