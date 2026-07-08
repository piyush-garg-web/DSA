void reverse(vector<int>& a, int start, int end) {
    while (start <= end) {
        swap(a[start], a[end]);
        start++;
        end--;
    }
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};