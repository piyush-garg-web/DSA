class Node {
	public:
	int data;
	Node* next;
	
	Node(int x) {
		data = x;
		next = NULL;
	}
};

class Solution {
	public:
	Node* mergeKLists(vector<Node*>& arr) {
		
		priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>> > pq;
		
		for (int i = 0; i<arr.size(); i++) {
			
			if (arr[i] != NULL) {
				pq.push({arr[i]->data, arr[i]});
			}
			
		}
		
		Node* dummy = new Node(-1);
		Node* tail = dummy;
		
		while (!pq.empty()) {
			
			auto it = pq.top();
			tail->next = it.second;
			tail = tail->next;
			
			pq.pop();
			
			if (it.second->next != NULL) {
				
				pq.push({it.second->next->data, it.second->next});
			}
			
		}
		
		return dummy->next;
	}
};
