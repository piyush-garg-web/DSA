class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        string ans = "";

        for (int i = s.length() - 1; i >= 0; i--) {
            while (i >= 0 && s[i] == ' ') {
                i--;
            }

            while (i >= 0 && s[i] != ' ') {
                temp.push_back(s[i]);
                i--;
            }

            reverse(temp.begin(), temp.end());

            if (temp.length() > 0) {
                ans += temp;
                ans += ' ';
                temp = "";
            }
        }

        ans.pop_back();
        return ans;
    }
};