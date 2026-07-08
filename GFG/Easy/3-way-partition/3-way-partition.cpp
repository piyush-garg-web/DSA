class Solution {
public:
    void threeWayPartition(vector<int>& arr, int a, int b) {
        int low = 0;
        int mid = 0;
        int high = arr.size() - 1;

        while (mid <= high) {
            if (arr[mid] < a) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } else if (arr[mid] > b) {
                swap(arr[high], arr[mid]);
                high--;
            } else {
                mid++;
            }
        }
    }
};
