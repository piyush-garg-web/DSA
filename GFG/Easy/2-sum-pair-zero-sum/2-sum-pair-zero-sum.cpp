class Solution {
public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        int i = 0;
        int j = arr.size() - 1;

        while (i < j) {
            int sum = arr[i] + arr[j];

            if (sum == 0) {
                ans.push_back({arr[i], arr[j]});

                int left = arr[i];
                int right = arr[j];

                while (i < j && arr[i] == left) {
                    i++;
                }

                while (i < j && arr[j] == right) {
                    j--;
                }

            } else if (sum < 0) {
                i++;
            } else {
                j--;
            }
        }

        return ans;
    }
};
