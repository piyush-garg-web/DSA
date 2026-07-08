class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for (auto edge : roads) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(make_pair(degree[i], i));
        }

        vector<int> cities(n, -1);
        int number = n;
        while (!pq.empty()) {
            auto element = pq.top();
            pq.pop();
            cities[element.second] = number;
            number--;
        }

        long long ans = 0;
        for (auto it : roads) {
            ans += cities[it[0]] + cities[it[1]];
        }

        return ans;
    }
};