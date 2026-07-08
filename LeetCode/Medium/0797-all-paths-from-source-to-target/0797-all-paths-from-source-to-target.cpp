class Solution {
    private:
    void solve (vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int>& temp,int currNode) {

         temp.push_back(currNode);

        if (currNode==graph.size()-1) {
            ans.push_back(temp);
            return;
        }
        for (auto i:graph[currNode]) {
            solve(graph,ans,temp,i);
            temp.pop_back();
        }

    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        int currNode=0;
        solve (graph,ans,temp,currNode);
        return ans;
    }
};