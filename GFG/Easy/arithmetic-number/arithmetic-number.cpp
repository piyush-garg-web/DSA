class Solution {
public:
    int inSequence(int a, int b, int c) {
        if (b == a) {
            return true;
        }

        if (c == 0) {
            return false;
        }

        if ((b - a) % c == 0 && (b - a) / c >= 0) {
            return true;
        }

        return false;
    }
};
