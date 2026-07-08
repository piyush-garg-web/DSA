class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rows = matrix.size();
        int columns = matrix[0].size();
        int total = rows * columns;
        int count = 0;
        int startingRow = 0;
        int endingRow = rows - 1;
        int startingColumn = 0;
        int endingColumn = columns - 1;

        while (count < total) {
            for (int i = startingColumn; count < total && i <= endingColumn; i++) {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            for (int i = startingRow; count < total && i <= endingRow; i++) {
                ans.push_back(matrix[i][endingColumn]);
                count++;
            }
            endingColumn--;

            for (int i = endingColumn; count < total && i >= startingColumn; i--) {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            for (int i = endingRow; count < total && i >= startingRow; i--) {
                ans.push_back(matrix[i][startingColumn]);
                count++;
            }
            startingColumn++;
        }

        return ans;
    }
};