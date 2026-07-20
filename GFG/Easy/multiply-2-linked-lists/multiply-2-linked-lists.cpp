class Node {
	public:
	int data;
	Node* next;
	Node(int key) {
		data = key;
		next = nullptr;
	}
};

class Solution {
	public:
	int multiplyTwoLists(Node *first, Node *second) {
		
		long long modulo = 1000000007;
		
		long long num1 = 0;
		long long num2 = 0;
		
		while (first != NULL) {
			
			num1 = (num1*10 + first->data)%modulo;
			first = first->next;
		}
		
		while (second != NULL) {
			
			num2 = (num2*10 + second->data)%modulo;
			second = second->next;
		}
		
		int ans = (num1*num2)%modulo;
		
		return ans;
		
	}
};
