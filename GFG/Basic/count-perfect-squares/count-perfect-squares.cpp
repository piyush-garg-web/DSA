class Solution {
public:
    int countSquares(int n) {
        int count = 0;

        for (int i = 1; i * i <= n; i++) {
            if (i * i < n) {
                count++;
            }
        }

        return count;
    }
};
