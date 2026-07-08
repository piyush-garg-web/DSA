class Solution {
public:
    void sort012(vector<int>& arr) {
        int l = 0;
        int h = arr.size() - 1;
        int m = 0;

        while (m <= h) {
            if (arr[m] == 1) {
                m++;
            } else if (arr[m] == 0) {
                swap(arr[l], arr[m]);
                l++;
                m++;
            } else {
                swap(arr[h], arr[m]);
                h--;
            }
        }
    }
};