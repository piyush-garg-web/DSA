class Solution {
private:
    bool solve(string& s, string& p) {
        vector<int> curr(p.length() + 1, 0);
        vector<int> next(p.length() + 1, 0);
        next[p.length()] = 1;

        for (int j = p.length() - 1; j >= 0; j--) {
            bool flag = true;

            for (int k = j; k < p.length(); k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }

            next[j] = flag;
        }

        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = p.length() - 1; j >= 0; j--) {
                if (s[i] == p[j] || p[j] == '?') {
                    curr[j] = next[j + 1];
                } else if (p[j] == '*') {
                    curr[j] = (curr[j + 1] || next[j]);
                } else {
                    curr[j] = false;
                }
            }
            next = curr;
        }

        return next[0];
    }

public:
    bool isMatch(string s, string p) {
        return solve(s, p);
    }
};