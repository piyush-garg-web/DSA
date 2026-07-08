class Solution {
private:
    int dijkstra(int i, int n,
                 unordered_map<int, list<pair<int, int>>>& adjList,
                 int distanceThreshold) {
        set<pair<int, int>> st;
        vector<int> distance(n, INT_MAX);
        int cities = 0;
        distance[i] = 0;
        st.insert(make_pair(0, i));

        while (!st.empty()) {
            auto top = *st.begin();
            int topDist = top.first;
            int topNode = top.second;

            if (topDist <= distanceThreshold && topNode != i) {
                cities++;
            }

            st.erase(st.begin());

            for (auto nbr : adjList[topNode]) {
                int nbrElement = nbr.first;
                int nbrDistance = nbr.second;

                if (topDist + nbrDistance < distance[nbrElement]) {
                    auto it = st.find(make_pair(distance[nbrElement], nbrElement));

                    if (it != st.end()) {
                        st.erase(it);
                    }

                    distance[nbrElement] = topDist + nbrDistance;
                    st.insert(make_pair(topDist + nbrDistance, nbrElement));
                }
            }
        }

        return cities;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, list<pair<int, int>>> adjList;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adjList[u].push_back(make_pair(v, w));
            adjList[v].push_back(make_pair(u, w));
        }

        int count = INT_MAX;
        int index = -1;

        for (int i = 0; i < n; i++) {
            int cities = dijkstra(i, n, adjList, distanceThreshold);

            if (cities <= count) {
                count = cities;
                index = i;
            }
        }

        return index;
    }
};