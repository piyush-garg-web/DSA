class Solution {
public:
    int maxSubStr(string &s) {
        int count0 = 0;
        int count1 = 0;
        int ans = 0;

        for (char ch : s) {
            if (ch == '0') {
                count0++;
            } else {
                count1++;
            }

            if (count0 == count1) {
                ans++;
            }
        }

        if (count0 != count1) {
            return -1;
        }

        return ans;
    }
};
