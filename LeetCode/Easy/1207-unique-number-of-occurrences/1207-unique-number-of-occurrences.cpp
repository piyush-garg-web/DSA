class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int freq[1001]={0};
        int a=arr[0];
        int j=0;
        freq[0]=1;
        for (int i=1;i<n;i++) {
            if (arr[i]==a) {
                freq[j]+=1;

            }
            else {
                j++;
                freq[j]+=1;
                a=arr[i];
            }
        }
        sort (freq,freq+j+1);
        for (int k=1;k<=j;k++) {
            if (freq[k]==freq[k-1]) {
                return false;
            }
        }
return true;
    }
};