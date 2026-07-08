class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int answerIndex = 0;

        while (i < chars.size()) {
            int j = i + 1;

            while (j < chars.size() && chars[i] == chars[j]) {
                j++;
            }

            chars[answerIndex] = chars[i];
            answerIndex++;

            int count = j - i;

            if (count > 1) {
                string cnt = to_string(count);
                int k = 0;

                while (k < cnt.length()) {
                    chars[answerIndex] = cnt[k];
                    answerIndex++;
                    k++;
                }
            }

            i = j;
        }

        return answerIndex;
    }
};