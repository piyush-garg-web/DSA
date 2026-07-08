void reverse (vector <int>& vect, int s, int e) {
    while (s<=e) {
        swap(vect[s],vect[e]);
        s++;
        e--;
    }
}
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for (int i=0; i<n;i++) {
            for (int j=i+1;j<n;j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for (int i=0;i<n;i++) {
            reverse(matrix[i],0,n-1);
        }
    }
};