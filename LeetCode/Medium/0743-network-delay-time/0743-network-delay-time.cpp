class Solution {
    private:
    void dijkstra (unordered_map<int,list<pair<int,int>>>& adjList,set<pair<int,int>>& st,
        vector<int>& distance,int k) {
            distance[k]=0;
            st.insert(make_pair(0,k));
            while (!st.empty()) {
                auto top=*st.begin();
                int topDist=top.first;
                int topNode=top.second;
                st.erase(st.begin());
                for (auto it:adjList[topNode]) {
                    int currDist=it.second;
                    int currNode=it.first;
                    if (topDist+currDist<distance[currNode]) {
                        auto f=st.find(make_pair(distance[currNode],currNode));
                        if (f!=st.end()) {
                            st.erase(f);
                        }
                        distance[currNode]=topDist+currDist;
                        st.insert(make_pair(topDist+currDist,currNode));
                    }
                }

            }
        }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,list<pair<int,int>>> adjList;
        for (int i=0;i<times.size();i++) {
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adjList[u].push_back(make_pair(v,w));
        }

        set<pair<int,int>> st;
        vector<int> distance (n+1,INT_MAX);
        dijkstra(adjList,st,distance,k);
int ans=INT_MIN;
for (int i=1;i<=n;i++) {
    if (distance[i]==INT_MAX) {
        return -1;
    }
    ans=max(ans,distance[i]);
}

return ans;

    }
};