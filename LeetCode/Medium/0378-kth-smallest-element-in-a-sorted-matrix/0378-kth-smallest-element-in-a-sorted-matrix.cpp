class Solution {
private:
    int countSmallerElements(int mid, vector<vector<int>>& matrix, int n) {
        int row = 0;
        int col = n - 1;
        int count = 0;
        while (row < n && col >= 0) {
            if (matrix[row][col] <= mid) {
                count += col + 1;
                row++;
            } else {
                col--;
            }
        }
        return count;
    };

public : 
int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int s = matrix[0][0];
        int e = matrix[n - 1][n - 1];
        int mid = -1;
        int count = 0;
        while (s <= e) {
            mid = s + ((e - s) / 2);
            count = countSmallerElements(mid, matrix, n);
            if (count < k) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return s;
    }
};