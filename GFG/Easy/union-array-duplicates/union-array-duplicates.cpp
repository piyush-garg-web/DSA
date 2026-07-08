class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> mp;
        vector<int> result;

        for (int i : a) {
            mp[i]++;
        }

        for (int i : b) {
            mp[i]++;
        }

        for (auto i : mp) {
            result.push_back(i.first);
        }

        return result;
    }
};