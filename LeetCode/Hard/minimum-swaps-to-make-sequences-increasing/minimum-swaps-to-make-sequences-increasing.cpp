class Solution {
private:
    int solve(int n, vector<int>& nums1, vector<int>& nums2) {
        int sWAP = 0;
        int noSwap = 0;
        int currSwap = 0;
        int currNoSwap = 0;

        for (int i = n; i >= 1; i--) {
            for (int j = 1; j >= 0; j--) {
                int ans = INT_MAX;
                int prev1 = nums1[i - 1];
                int prev2 = nums2[i - 1];

                if (j) {
                    swap(prev1, prev2);
                }

                if (nums1[i] > prev1 && nums2[i] > prev2) {
                    ans = min(ans, noSwap);
                }

                if (nums1[i] > prev2 && nums2[i] > prev1) {
                    ans = min(ans, 1 + sWAP);
                }

                if (j) {
                    currSwap = ans;
                } else {
                    currNoSwap = ans;
                }
            }
            sWAP = currSwap;
            noSwap = currNoSwap;
        }

        return min(sWAP, noSwap);
    }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        return solve(n, nums1, nums2);
    }
};