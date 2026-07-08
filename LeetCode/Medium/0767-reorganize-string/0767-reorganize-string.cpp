class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        int arr[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            arr[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) {
                pq.push({arr[i], char('a' + i)});
            }
        }

        string ans;

        while (pq.size() > 1) {
            auto maxi = pq.top();
            pq.pop();
            auto secondMaxi = pq.top();
            pq.pop();
            ans.push_back(maxi.second);
            ans.push_back(secondMaxi.second);
            maxi.first--;
            secondMaxi.first--;
            if (maxi.first > 0) {
                pq.push({maxi.first, maxi.second});
            }
            if (secondMaxi.first > 0) {
                pq.push({secondMaxi.first, secondMaxi.second});
            }
        }

        if (!pq.empty()) {
            auto lastElement=pq.top();
            if ((lastElement.first)>1) {
                return "";
            }
            else {
                ans.push_back(lastElement.second);
            }
        }
        return ans;
    }
};