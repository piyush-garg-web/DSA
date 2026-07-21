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
	
	Node* removeLeadingZeroes (Node* head) {
		
		while (head && head->data == 0) {
			head = head->next;
		}
		
		if (head == NULL) {
			return new Node(0);
		}
		
		return head;
	}
	
	Node* reverse (Node* head) {
		
		Node* prev = NULL;
		Node* curr = head;
		
		while (curr != NULL) {
			Node* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		
		return prev;
	}
	
	public:
	
	Node* addTwoLists(Node* head1, Node* head2) {
		
		Node* dummy = new Node(-1);
		Node* tail = dummy;
		
		head1 = removeLeadingZeroes(head1);
		head2 = removeLeadingZeroes(head2);
		
		head1 = reverse(head1);
		head2 = reverse(head2);
		
		int carry = 0;
		
		while (head1 || head2 || carry) {
			
			int sum = carry;
			
			if (head1) {
				sum = sum + head1->data;
				head1 = head1->next;
			}
			
			if (head2) {
				sum = sum + head2->data;
				head2 = head2->next;
			}
			
			tail->next = new Node(sum%10);
			tail = tail->next;
			
			carry = sum/10;
			
		}
		
		Node* ans = reverse(dummy->next);
		delete dummy;
		
		return ans;
	}
};
