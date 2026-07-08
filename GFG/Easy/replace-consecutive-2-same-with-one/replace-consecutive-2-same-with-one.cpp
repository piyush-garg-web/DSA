class Solution {
public:
    string removeDuplicates(string& s) {
        if (s.empty()) {
            return "";
        }

        string ans = "";
        ans += s[0];

        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) {
                ans += s[i];
            }
        }

        return ans;
    }
};
