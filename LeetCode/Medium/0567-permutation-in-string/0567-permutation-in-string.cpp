bool isEqual (int arr1[26], int arr2[26]) {
for (int i=0;i<26;i++) {
    if (arr1[i]!=arr2[i]) {
        return 0;
    }
}
return 1;
}


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        int arr1[26]={0};
        for (int i=0;i<n;i++) {
            char ch=s1[i];
            int index=ch-'a';
            arr1[index]++;
        }

        int arr2[26]={0};
        int i=0;
        while (i<n && i<m) {
            char ch=s2[i];
            int index=ch-'a';
            arr2[index]++;
            i++;
        }
       if (isEqual(arr1,arr2)) {
        return 1;
       }

       while (i<m) {
        char newChar=s2[i];
        int newIndex=newChar-'a';
        arr2[newIndex]++;
        char oldChar=s2[i-n];
        int oldIndex=oldChar-'a';
        arr2[oldIndex]--;
        if (isEqual(arr1,arr2)) {
            return 1;
        }
        i++;
       }
       return 0;
    }
};