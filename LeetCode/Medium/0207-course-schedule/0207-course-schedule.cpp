class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

 unordered_map<int,list<int>> adj;
 vector<int> indegree (numCourses,0);
 for (int i=0;i<prerequisites.size();i++) {
    int u=prerequisites[i][0];
    int v=prerequisites[i][1];
    adj[u].push_back(v);
    indegree[v]++;
 }       

 vector<int> topo;
 queue<int> q;
for (int i=0;i<indegree.size();i++) {
    if (indegree[i]==0) {
        q.push(i);
    }
}

while (!q.empty()) {
    int top=q.front();
    q.pop();
    topo.push_back(top);
        for (int nbr:adj[top]) {
        indegree[nbr]--;
        if (indegree[nbr]==0) {
            q.push(nbr);
        }
    }
}

if (topo.size()==numCourses) {
    return true;
}
else {
    return false;
}
    }
};