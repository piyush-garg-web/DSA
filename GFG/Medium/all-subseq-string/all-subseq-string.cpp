class Solution {
private:
    void solve(string &s, vector<string>& ans, int index, string curr) {
        if (index == s.size()) {
            ans.push_back(curr);
            return;
        }

        solve(s, ans, index + 1, curr + s[index]);
        solve(s, ans, index + 1, curr);
    }

public:
    vector<string> powerSet(string &s) {
        int n = s.size();
        vector<string> ans;
        string curr = "";

        solve(s, ans, 0, curr);

        sort(ans.begin(), ans.end());

        return ans;
    }
};
