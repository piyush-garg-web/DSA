class Solution {
public:
    bool canRearrange(string& s) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        int maxFreq = INT_MIN;

        for (int x : freq) {
            maxFreq = max(maxFreq, x);
        }

        if (maxFreq <= (n + 1) / 2) {
            return true;
        }

        return false;
    }
};
