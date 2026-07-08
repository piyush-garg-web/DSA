class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.length();

        while (s.find(part) != -1) {
            int pos = s.find(part);
            s.erase(pos, n);
        }

        return s;
    }
};