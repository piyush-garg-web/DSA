class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        int jumps=0;
        int l=0;
        int r=0;
        
        if (arr[0]==0) {
            return -1;
        }
    
        if (n==1) {
            return 0;
        }
        
        int farthest;
        while (r<n-1) {
            
            farthest=r;
            
            for (int i=l;i<=r;i++) {
                farthest=max(farthest,i+arr[i]);
            }
            
            if (farthest==r) {
                return -1;
            }
            
            l=r+1;
            r=farthest;
            jumps++;
        }
        
        return jumps;
        
        
        
    }
};
