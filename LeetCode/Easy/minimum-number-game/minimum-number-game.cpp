#include<queue>
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
         vector<int> arr;
        priority_queue<int,vector<int>,greater<int>> pq;
        for (int i=0;i<nums.size();i++) {
            pq.push(nums[i]);
        }
       while (pq.size()) {
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        arr.push_back(b);
        arr.push_back(a);
       }
       return arr;

        
    }
};