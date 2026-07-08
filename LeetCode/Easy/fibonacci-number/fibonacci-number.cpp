class Solution {
public:
    int fib(int n) {
        int first = 0;
        int second = 1;

        if (n == 0) {
            return first;
        }

        if (n == 1) {
            return second;
        }

        for (int i = 2; i <= n; i++) {
            int temp = second;
            second = first + second;
            first = temp;
        }

        return second;
    }
};