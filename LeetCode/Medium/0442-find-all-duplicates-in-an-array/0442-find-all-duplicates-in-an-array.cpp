class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
   vector<int> result;
    for (int i=0;i<n;i++) {
        int element=abs(nums[i]);
        int position=element-1;
        if (nums[position]<0) {
            result.push_back(element);
        }
        else {
            nums[position]=-nums[position];
        }
    }
    
    return result;

    }
};