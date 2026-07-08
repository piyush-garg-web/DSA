class Solution {
public:
    int secFrequent(vector<string> &arr) {
        if (arr.size() <= 1) {
            return -1;
        }

        unordered_map<string, int> map;

        for (string it : arr) {
            map[it]++;
        }

        if (map.size() == 1) {
            return -1;
        }

        int maxFreq = 0;
        int secondMax = 0;

        for (auto it : map) {
            int freq = it.second;

            if (freq > maxFreq) {
                secondMax = maxFreq;
                maxFreq = freq;
            } else if (freq > secondMax && freq < maxFreq) {
                secondMax = freq;
            }
        }

        if (secondMax == 0) {
            return -1;
        }

        return secondMax;
    }
};
