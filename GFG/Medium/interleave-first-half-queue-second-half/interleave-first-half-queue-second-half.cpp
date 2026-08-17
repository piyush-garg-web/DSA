class Solution {
	public:
	void rearrangeQueue(queue<int> &q) {
		
		queue<int> first;
		queue<int> second;
		
		int n = q.size();
		
		if (n == 1) {
			return;
		}
		
		for (int i = 0; i<n/2; i++) {
			
			first.push(q.front());
			q.pop();
		}
		
		while (!q.empty()) {
			
			second.push(q.front());
			q.pop();
		}
		
		while (!first.empty()) {
			
			q.push(first.front());
			first.pop();
			
			q.push(second.front());
			second.pop();
			
		}
		
	}
};
