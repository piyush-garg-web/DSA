class compare {
public:
    bool operator()(pair<int, string> a, pair<int, string> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> count;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            count[words[i]]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, compare>
            pq;
        for (auto element : count) {
            pq.push({element.second, element.first});
            if (pq.size() > k) {
                pq.pop();
            }
    }

    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
}
;