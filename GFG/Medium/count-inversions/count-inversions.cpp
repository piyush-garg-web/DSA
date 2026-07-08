class Solution {
private:
    int merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int l = low;
        int r = mid + 1;
        int result = 0;

        while (l <= mid && r <= high) {
            if (arr[l] <= arr[r]) {
                temp.push_back(arr[l]);
                l++;
            } else {
                temp.push_back(arr[r]);
                result += mid - l + 1;
                r++;
            }
        }

        while (l <= mid) {
            temp.push_back(arr[l]);
            l++;
        }

        while (r <= high) {
            temp.push_back(arr[r]);
            r++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return result;
    }

    int mergeSort(vector<int>& arr, int low, int high) {
        int count = 0;

        if (low >= high) {
            return count;
        }

        int mid = low + (high - low) / 2;

        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
        return count;
    }

public:
    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};
