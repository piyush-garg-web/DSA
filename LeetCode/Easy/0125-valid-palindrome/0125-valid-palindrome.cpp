bool toLowerCase (char ch) {
    if ((ch>='a' && ch<='z') || (ch>='0' && ch<='9')) {
        return 1;
    }
    else {
        return 0;
    }
}

bool isValid (char ch) {
    if ((ch>='a' && ch<='z') || (ch>='0' && ch<='9') || (ch>='A' && ch<='Z')) {
        return 1;
    }
    else {
        return 0;
    }
}

class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for (int i=0;i<s.size();i++) {
            if (isValid(s[i])) {
                temp.push_back(s[i]);
            }
        }
        for (int i=0;i<temp.size();i++) {
if (toLowerCase(temp[i])) {
temp[i]=temp[i];
}
else {
    temp[i]=temp[i]-'A'+'a';
}
        }
        int start=0;
        int end=temp.size()-1;
        while (start<=end) {
            if (temp[start]!=temp[end]) {
                return 0;
            }
            start++;
            end--;
        }
        return 1;
    }
};