class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> dp;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int diff = arr[i] - difference;

            if (dp.count(diff)) {
                dp[arr[i]] = 1 + dp[diff];
            } else {
                dp[arr[i]] = 1;
            }

            ans = max(ans, dp[arr[i]]);
        }

        return ans;
    }
};