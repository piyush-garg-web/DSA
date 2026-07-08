class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;

        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto pair : count) {
            pq.push({pair.second, pair.first});
        }

        string ans = "";

        while (!pq.empty()) {
            int cnt = pq.top().first;
            int character = pq.top().second;

            while (cnt != 0) {
                ans.push_back(character);
                cnt--;
            }

            pq.pop();
        }

        return ans;
    }
};