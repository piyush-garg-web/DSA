class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int lsum=0;
        int rsum=0;
        for (int i=1;i<n;i++) {
            rsum+=nums[i];
        }
        if (lsum==rsum) {
            return 0;
        }
     for (int i=1;i<n;i++) {
        lsum+=nums[i-1];
        rsum-=nums[i];
        if (lsum==rsum) {
            return i;
        }
     }
     return -1;

        }
};