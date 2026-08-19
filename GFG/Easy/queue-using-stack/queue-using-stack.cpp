class myQueue {
	
	stack<int> st1;
	stack<int> st2;
	
	public:
	myQueue() {
		
	}
	
	void enqueue(int x) {
		
		st1.push(x);
	}
	
	void dequeue() {
		
		if (st2.empty()) {
			
			while (!st1.empty()) {
				st2.push(st1.top());
				st1.pop();
			}
		}
		
		if (!st2.empty()) {
			
			st2.pop();
		}
	}
	
	int front() {
		
		if (st2.empty()) {
			
			while (!st1.empty()) {
				st2.push(st1.top());
				st1.pop();
			}
		}
		
		if (st2.empty()) {
			return - 1;
		}
		
		return st2.top();
	}
	
	int size() {
		
		return st1.size() + st2.size();
	}
};
