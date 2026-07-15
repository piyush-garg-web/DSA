class Node {
	public:
	int data;
	Node *next;
	Node(int x) {
		data = x;
		next = nullptr;
	}
};

class Solution {
	public:
	Node* removeDuplicates(Node* head) {
		
		unordered_map <int, int> mp;
		Node* curr = head;
		Node*prev = NULL;
		
		while (curr != NULL) {
			
			if (mp[curr->data]>0) {
				Node*temp = curr;
				prev->next = curr->next;
				curr = prev->next;
				delete temp;
			}
			
			else {
				mp[curr->data]++;
				prev = curr;
				curr = curr->next;
			}
		}
		
		return head;
		
	}
};
