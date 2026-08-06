class Solution {
	public:
	struct Info {
		int start;
		int finish;
		int index;
	};
	
	static bool cmp (Info a, Info b) {
		
		if (a.finish == b.finish) {
			return a.index<b.index;
		}
		
		return a.finish<b.finish;
	};
	
	public:
	vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
		
		vector<Info> schedule;
		
		for (int i = 0; i<s.size(); i++) {
			schedule.push_back({s[i], f[i], i + 1});
		}
		
		sort(schedule.begin(), schedule.end(), cmp);
		
		vector<int> ans;
		
		int lastFinish = -1;
		
		for (auto meeting :schedule) {
			
			if (meeting.start>lastFinish) {
				ans.push_back(meeting.index);
				lastFinish = meeting.finish;
			}
		}
		
		sort(ans.begin(), ans.end());
		
		return ans;
		
	}
};
