class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int currSum=0;
        int maxSum=INT_MIN;
        
        for (int i=0;i<arr.size();i++) {
            currSum+=arr[i];
            maxSum=max(maxSum,currSum);
            if (currSum<0) {
                currSum=0;
            }
        }
        
        return maxSum;
        
    }
};