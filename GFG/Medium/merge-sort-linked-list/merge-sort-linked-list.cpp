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
	private:
	Node* merge (Node* left, Node* right) {
		Node* dummy = new Node(-1);
		Node* tail = dummy;
		
		while (left != NULL && right != NULL) {
			
			if (left->data<right->data) {
				tail->next = left;
				tail = tail->next;
				left = left->next;
			}
			
			else {
				tail->next = right;
				tail = tail->next;
				right = right->next;
			}
			
			if (left != NULL) {
				tail->next = left;
			}
			
			else {
				tail->next = right;
			}
		}
		
		return dummy->next;
	}
	
	Node* findMiddle (Node* head) {
		Node* slow = head;
		Node* fast = head->next;
		
		while (fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}
		
		return slow;
		
	}
	
	public:
	Node* mergeSort(Node* head) {
		
		if (head == NULL || head->next == NULL) {
			return head;
		}
		
		Node* middle = findMiddle(head);
		Node* rightHead = middle->next;
		middle->next = NULL;
		Node* leftHead = head;
		
		leftHead = mergeSort(leftHead);
		rightHead = mergeSort(rightHead);
		
		return merge(leftHead, rightHead);
		
	}
};
