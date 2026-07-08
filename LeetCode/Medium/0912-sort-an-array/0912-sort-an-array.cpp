class Solution {
private:
    void buildMaxHeap(vector<int>& nums) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, i, n);
        }
    }

    void heapify(vector<int>& nums, int i, int n) {

        while (true) {

            int largest = i;
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;
            if (leftIndex < n && nums[largest] < nums[leftIndex]) {
                largest = leftIndex;
            }

            if (rightIndex < n && nums[largest] < nums[rightIndex]) {
                largest = rightIndex;
            }

            if (largest == i) {
                break;
            }

            swap(nums[i], nums[largest]);
            i = largest;
        }
    }

    void solve(vector<int>& nums) {
        int size = nums.size();
        while (size > 1) {
            swap(nums[0], nums[size - 1]);
            size--;
            heapify(nums, 0, size);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        buildMaxHeap(nums);
        solve(nums);
        return nums;
    }
};