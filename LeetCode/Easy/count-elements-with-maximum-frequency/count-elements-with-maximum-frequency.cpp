class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> count;
        int maxFreq=INT_MIN;
        int n=nums.size();
        int ans=0;
        for (int i=0;i<n;i++) {
            count[nums[i]]++;
            maxFreq=max(maxFreq,count[nums[i]]);
        }

for (auto i:count) {
    if (i.second==maxFreq) {
        ans+=i.second;
    }
}

return ans;
        
    }
};