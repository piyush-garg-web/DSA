class Solution {
public:
    bool isPowerOfTwo(int n) {
        int answer = 1;

        for (int i = 0; i <= 30; i++) {
            if (answer == n) {
                return true;
            }

            if (answer < (INT_MAX) / 2) {
                answer = answer * 2;
            }
        }

        return false;
    }
};