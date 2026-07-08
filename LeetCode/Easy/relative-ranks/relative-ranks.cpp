class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }

        vector<string> ans(n);
        int place = 1;

        while (!pq.empty()) {
            int scoreValue = pq.top().first;
            int position = pq.top().second;

            if (place == 1) {
                ans[position] = "Gold Medal";
            } else if (place == 2) {
                ans[position] = "Silver Medal";
            } else if (place == 3) {
                ans[position] = "Bronze Medal";
            } else {
                ans[position] = to_string(place);
            }

            place++;
            pq.pop();
        }

        return ans;
    }
};