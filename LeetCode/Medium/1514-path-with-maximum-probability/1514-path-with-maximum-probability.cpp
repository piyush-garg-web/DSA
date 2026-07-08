class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        unordered_map<int, list<pair<int, double>>> adj;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back(make_pair(v, prob));
            adj[v].push_back(make_pair(u, prob));
        }

        vector<double> maxProb(n, 0.0);
        priority_queue<pair<double, int>> pq;
        maxProb[start_node] = 1.0;
        pq.push(make_pair(maxProb[start_node], start_node));

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            double topProb = top.first;
            int topNode = top.second;

            if (topNode == end_node) {
                return topProb;
            }

            for (auto nbr : adj[topNode]) {
                int currNode = nbr.first;
                double currProb = nbr.second;

                if (topProb * currProb > maxProb[currNode]) {
                    maxProb[currNode] = topProb * currProb;
                    pq.push(make_pair(topProb * currProb, currNode));
                }
            }
        }

        return 0.0;
    }
};