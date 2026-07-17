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
	
	private:
	
	Node* reverse (Node* head) {
		
		Node* prev = NULL;
		Node* curr = head;
		
		while (curr != NULL) {
			Node* temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		
		return prev;
	}
	
	public:
	bool isPalindrome(Node *head) {
		
		if (head == NULL || head->next == NULL) {
			return true;
		}
		
		Node* slow = head;
		Node* fast = head;
		
		while (fast->next != NULL && fast->next->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}
		
		slow->next = reverse(slow->next);
		
		Node* first = head;
		Node* second = slow->next;
		
		while (second != NULL) {
			if (first->data != second->data) {
				return false;
			}
			
			first = first->next;
			second = second->next;
		}
		
		return true;
		
	}
};
