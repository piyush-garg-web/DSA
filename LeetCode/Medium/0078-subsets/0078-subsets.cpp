void solve (vector<vector<int>>& ans,vector<int> output,vector<int> nums, int index) {
if (index>=nums.size()) {
    ans.push_back(output);
    return;
}
solve(ans,output,nums,index+1);
int element=nums[index];
output.push_back(element);
solve (ans,output,nums,index+1);
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        vector<int> output;
        solve(ans,output,nums,index);
        return ans;
    }
};