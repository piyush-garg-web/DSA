class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        queue<pair<int, int>> week;
        queue<pair<int, int>> month;
        int ans = 0;

        for (int day : days) {
            while (!week.empty() && day >= week.front().first + 7) {
                week.pop();
            }

            while (!month.empty() && day >= month.front().first + 30) {
                month.pop();
            }

            week.push({day, ans + costs[1]});
            month.push({day, ans + costs[2]});
            ans = min(ans + costs[0], min(week.front().second, month.front().second));
        }

        return ans;
    }
};