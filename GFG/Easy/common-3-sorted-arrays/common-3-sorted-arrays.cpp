class Solution {
public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < a.size() && j < b.size() && k < c.size()) {
            if (a[i] == b[j] && b[j] == c[k]) {
                if (ans.empty() || ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }

                i++;
                j++;
                k++;

            } else {
                int mini = min(a[i], min(b[j], c[k]));

                if (mini == a[i]) {
                    i++;
                } else if (mini == b[j]) {
                    j++;
                } else {
                    k++;
                }
            }
        }

        return ans;
    }
};