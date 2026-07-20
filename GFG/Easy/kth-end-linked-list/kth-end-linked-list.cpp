class Node {
	public:
	int data;
	Node* next;
	Node(int x) {
		data = x;
		next = nullptr;
	}
}; 

class Solution {
	public:
	int getKthFromLast(Node* head, int k) {
		
		int total = 0;
		Node* curr = head;
		
		while (curr != NULL) {
			total++;
			curr = curr->next;
		}
		
		int required = total - k + 1;
		
		if (required <= 0) {
			return - 1;
		}
		
		int count = 1;
		Node* temp = head;
		
		while (count<required) {
			count++;
			temp = temp->next;
		}
		
		return temp->data;
		
	}
};
