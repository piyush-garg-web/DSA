#include <stack>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> result;

        for (int i = 0; i < tokens.size(); i++) {
            string ch = tokens[i];

            if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                int value1 = result.top();
                result.pop();
                int value2 = result.top();
                result.pop();

                if (ch == "+") {
                    result.push(value2 + value1);
                } else if (ch == "-") {
                    result.push(value2 - value1);
                } else if (ch == "*") {
                    result.push(value2 * value1);
                } else {
                    result.push(value2 / value1);
                }
            } else {
                result.push(stoi(ch));
            }
        }

        return result.top();
    }
};