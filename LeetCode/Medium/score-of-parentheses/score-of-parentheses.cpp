#include <stack>

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int> st;

        for (int i = 0; i < s.length(); i++) {
            int val = 0;
            char ch = s[i];

            if (ch == '(') {
                st.push(0);
            } else {
                while (st.top() != 0) {
                    val = val + st.top();
                    st.pop();
                }

                val = max(2 * val, 1);
                st.pop();
                st.push(val);
            }
        }

        while (!st.empty()) {
            score = score + st.top();
            st.pop();
        }

        return score;
    }
};