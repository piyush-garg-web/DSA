class Solution {
public:
    int countOccurence(vector<int>& arr, int k) {
        int occur = arr.size() / k;
        unordered_map<int, int> map;

        for (int i = 0; i < arr.size(); i++) {
            map[arr[i]]++;
        }

        int ans = 0;

        for (auto it : map) {
            if (it.second > occur) {
                ans++;
            }
        }

        return ans;
    }
};
