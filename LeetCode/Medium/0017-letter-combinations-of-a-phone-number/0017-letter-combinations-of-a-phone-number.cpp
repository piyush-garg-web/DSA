void solve(vector<string>& ans, int index, string output, string mapping[], string digits) {
    if (index >= digits.length()) {
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string value = mapping[number];

    for (int i = 0; i < value.length(); i++) {
        output.push_back(value[i]);
        solve(ans, index + 1, output, mapping, digits);
        output.pop_back();
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int index = 0;
        string output;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(ans, index, output, mapping, digits);
        return ans;
    }
};