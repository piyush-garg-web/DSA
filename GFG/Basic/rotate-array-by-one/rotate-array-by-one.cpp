class Solution {
  public:
    void rotate(vector<int> &arr) {
      int last=arr[arr.size()-1];
      for (int i=arr.size()-2;i>=0;i--) {
          arr[i+1]=arr[i];
      }
      
      arr[0]=last;
        
    }
};