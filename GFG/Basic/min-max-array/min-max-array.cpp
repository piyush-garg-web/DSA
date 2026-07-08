class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
     vector<int> result;
     int mini=INT_MAX;
     int maxi=INT_MIN;
     for (int i=0;i<arr.size();i++) {
         if (arr[i]<mini) {
             mini=arr[i];
         }
         
         if (arr[i]>maxi) {
             maxi=arr[i];
         }
     }
     
     result.push_back(mini);
     result.push_back(maxi);
     return result;
        
    }
};