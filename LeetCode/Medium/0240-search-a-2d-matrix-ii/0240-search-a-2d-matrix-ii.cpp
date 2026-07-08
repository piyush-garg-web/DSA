int binarySearch (vector <int>& vect, int n, int key) {
    int s=0;
    int e=n-1;
    int mid = s +(e-s)/2;
    while (s<=e) {
        if (vect[mid]==key) {
            return 1;
        }
        else if (vect[mid]>key) {
            e=mid-1;
        }
        else {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int columns=matrix[0].size();
for (int i=0; i<rows;i++) {
    int n =binarySearch(matrix[i],columns,target);
    if (n==1) {
        return 1;
    }
}
return 0;
    }
};