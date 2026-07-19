class Node {
	public:
	int data;
	Node* next;
	
	Node(int val) {
		data = val;
		next = nullptr;
	}
};

class Solution {
	public:
	
	Node *divide(Node *head) {
		
		if (head->next == NULL) {
			return head;
		}
		
		Node* dummyEven = new Node(-1);
		Node* dummyOdd = new Node(-1);
		
		Node* even = dummyEven;
		Node* odd = dummyOdd;
		
		Node* curr = head;
		
		while (curr != NULL) {
			
			if (curr->data%2 == 0) {
				even->next = curr;
				even = even->next;
			}
			
			else {
				odd->next = curr;
				odd = odd->next;
			}
			
			curr = curr->next;
		}
		
		even->next = dummyOdd->next;
		odd->next = NULL;
		
		Node* newHead = dummyEven->next;
		
		delete dummyEven;
		delete dummyOdd;
		
		return newHead;
	}
};
