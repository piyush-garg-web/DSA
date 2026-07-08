class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int columns=matrix[0].size();
        int total=rows*columns;
        int s=0;
        int e=total-1;
        int mid=s +(e-s)/2;
        while (s<=e) {
            int element=matrix[mid/columns][mid%columns];
            if (element==target) {
                return 1;
            }
            else if (element<target) {
                s=mid+1;
            }
            else {
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return 0;
    }
};