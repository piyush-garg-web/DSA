class Solution {
private:
    int solve(int n, vector<vector<int>>& cuboids) {
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = n - 1; prev >= -1; prev--) {
                int include = 0;

                if (prev == -1 || (cuboids[curr][0] >= cuboids[prev][0] &&
                                   cuboids[curr][1] >= cuboids[prev][1] &&
                                   cuboids[curr][2] >= cuboids[prev][2])) {
                    include = cuboids[curr][2] + nextRow[curr + 1];
                }

                int exclude = 0 + nextRow[prev + 1];
                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }

        return nextRow[0];
    }

public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();

        for (auto& it : cuboids) {
            sort(it.begin(), it.end());
        }

        sort(cuboids.begin(), cuboids.end());

        return solve(n, cuboids);
    }
};