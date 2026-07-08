class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,list<string>> adj;
        unordered_map<string,int> indegree;
        for (int i=0;i<recipes.size();i++) {
            for (auto j:ingredients[i]) {
                adj[j].push_back(recipes[i]);
            }
            indegree[recipes[i]]=ingredients[i].size();
        }

        queue<string> q;
        for (auto it:supplies) {
            q.push(it);
        }

vector<string> ans;

        while (!q.empty()) {
string curr=q.front();
q.pop();
for (auto nbr:adj[curr]) {
    indegree[nbr]--;
    if (indegree[nbr]==0) {
        ans.push_back(nbr);
        q.push(nbr);
    }
}
        }
        return ans;
        
    }
};