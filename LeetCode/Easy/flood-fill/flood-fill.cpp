class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& image, int color,
             int oldColor) {

        int n = image.size();
        int m = image[0].size();

        if (row < 0 || row >= n || col < 0 || col >= m) {

            return;
        }

        if (image[row][col] != oldColor) {

            return;
        }

        image[row][col] = color;

        dfs(row - 1, col, image, color, oldColor);
        dfs(row, col + 1, image, color, oldColor);
        dfs(row + 1, col, image, color, oldColor);
        dfs(row, col - 1, image, color, oldColor);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        int oldColor = image[sr][sc];

        if (image[sr][sc] == color) {

            return image;
        }

        dfs(sr, sc, image, color, oldColor);

        return image;
    }
};