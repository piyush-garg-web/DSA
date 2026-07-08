class Solution {
private:
    int solve(int n, vector<int>& slices) {

        vector<int> prev1(n + 2, 0);
        vector<int> curr1(n + 2, 0);
        vector<int> next1(n + 2, 0);

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 1; j <= n / 3; j++) {
                int include = slices[i] + next1[j - 1];
                int exclude = 0 + curr1[j];
                prev1[j] = max(include, exclude);
            }
            next1 = curr1;
            curr1 = prev1;
        }

        int ans1 = curr1[n / 3];

        vector<int> prev2(n + 2, 0);
        vector<int> curr2(n + 2, 0);
        vector<int> next2(n + 2, 0);

        for (int i = n - 1; i >= 1; i--) {
            for (int j = 1; j <= n / 3; j++) {
                int include = slices[i] + next2[j - 1];
                int exclude = 0 + curr2[j];
                prev2[j] = max(include, exclude);
            }

            next2 = curr2;
            curr2 = prev2;
        }

        int ans2 = curr2[n / 3];

        return max(ans1, ans2);
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        return solve(n, slices);
    }
};