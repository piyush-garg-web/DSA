class Solution {
public:
    string removeDuplicates(string s) {
        int i = -1;

        for (int j = 0; j < s.length(); j++) {
            if (i >= 0 && s[i] == s[j]) {
                i--;
            } else {
                s[++i] = s[j];
            }
        }

        return s.substr(0, i + 1);
    }
};