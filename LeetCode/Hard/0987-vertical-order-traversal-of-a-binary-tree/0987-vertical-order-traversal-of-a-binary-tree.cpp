/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <queue>
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> subans;
        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        if (root == NULL) {
            return ans;
        }
        q.push(make_pair(root, make_pair(0, 0)));
        while (!q.empty()) {
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();
            int horDist = temp.second.first;
            int level = temp.second.second;
            TreeNode* node = temp.first;

            nodes[horDist][level].push_back(temp.first->val);
            if (node->left) {
                q.push(
                    make_pair(node->left, make_pair(horDist - 1, level + 1)));
            }
            if (node->right) {
                q.push(
                    make_pair(node->right, make_pair(horDist + 1, level + 1)));
            }
        }

        for (auto i : nodes) {
            for (auto j : i.second) {
                sort(j.second.begin(),j.second.end());
                for (int val : j.second) {
                    subans.push_back(val);
            }
            }
            ans.push_back(subans);
            subans.clear();
        }

        return ans;
    }
};