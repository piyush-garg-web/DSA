class Solution {
private:
    vector<int> nSE(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    vector<int> pSE(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);

        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    int largestArea(vector<int>& histogram, int n) {
        vector<int> next = nSE(histogram, n);
        vector<int> prev = pSE(histogram, n);

        int maxArea = INT_MIN;

        for (int i = 0; i < n; i++) {
            int l = histogram[i];
            if (next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int a = l * b;
            maxArea = max(maxArea, a);
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi = INT_MIN;
        vector<int> histogram(matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    histogram[j]++;
                } else {
                    histogram[j] = 0;
                }
            }

            maxi = max(maxi, largestArea(histogram, matrix[0].size()));
        }

        return maxi;
    }
};