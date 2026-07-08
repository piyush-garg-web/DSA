class Solution {
    void dijkstra(char src, vector<vector<int>>& distance,
                  unordered_map<char, list<pair<char, int>>>& adj) {
        priority_queue<pair<int, char>, vector<pair<int, char>>,
                       greater<pair<int, char>>>
            pq;

        pq.push(make_pair(0, src));
        int source = src - 'a';
        distance[source][source] = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            char currChar = top.second;
            int currDist = top.first;
            pq.pop();
            for (auto nbr : adj[currChar]) {
                char newChar1 = nbr.first;
                int newChar2 = newChar1 - 'a';
                int newDist = nbr.second;
                if (currDist + newDist < distance[source][newChar2]) {
                    pq.push(make_pair(currDist + newDist, newChar1));
                    distance[source][newChar2] = currDist + newDist;
                }
            }
        }
    }

public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        unordered_map<char, list<pair<char, int>>> adj;
        for (int i = 0; i < original.size(); i++) {
            char u = original[i];
            char v = changed[i];
            int c = cost[i];
            adj[u].push_back(make_pair(v, c));
        }

        vector<vector<int>> distance(26, vector<int>(26, INT_MAX));

        for (int i = 0; i < 26; i++) {
            char src = i + 'a';
            dijkstra(src, distance, adj);
        }

        long long ans=0;
        for (int i=0;i<source.length();i++) {
            int a=source[i]-'a';
            int b=target[i]-'a';
            if (a==b) {
                ans+=0;
            }
            if (distance[a][b]==INT_MAX) {
                return -1;
            }
            ans+=distance[a][b];
        }

        return ans;
    }
};