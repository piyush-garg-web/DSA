class Solution {
    private:
    static bool cmp (vector<int>& a,vector<int>& b) {
        if (a[0]==b[0]) {
            return a[1]>b[1];
        }

        return a[0]<b[0];
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        if (n==0) {
            return 0;
        }

        if (n==1) {
            return 1;
        }
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        for (int i=1;i<n;i++) {
            int element=envelopes[i][1];
            if (element>ans.back()) {
                ans.push_back(element);
            }

            else{
               int index=lower_bound(ans.begin(),ans.end(),element)-ans.begin();
               ans[index]=element; 
            }
        }

        return ans.size();
    }
};