//Given a linked list, swap every two adjacent nodes and return its head.
//
//Example:
//
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//Note :
//
//	Your algorithm should use only constant extra space.
//	You may not modify the values in the list's nodes, only nodes itself may be changed.

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>


using namespace std;

//*Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};


class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL) {
			return NULL;
		}
		else if (head->next == NULL) {
			return head;
		}
		//save the result;
		ListNode * result = head->next;
		//front and back pointer with interval 2;
		ListNode front(0);
		ListNode * back = head->next;
		front.next = head;
		//create a cur_ptr to change the value;or the front is copied by value, which isn't 
		//enough to replace;
		ListNode * cur = &front;
		while (1) {
			//caution the moving sequence;
			cur->next->next = back->next;
			back->next = cur->next;
			cur->next = back;
			if (back->next->next != NULL&&back->next->next->next != NULL) {
				//back ptr move 3;
				//cur ptr move 2;
				back = back->next->next->next;
				cur = cur->next->next;
			}
			else {
				break;
			}
		}
		return result;
	}
};



int main() {
	ListNode node1(1), node2(2), node3(3), node4(4);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	Solution sol;
	auto ans = sol.swapPairs(&node1);
	while (ans != NULL) {
		cout << ans->val << "  ";
		ans = ans->next;
	}
	cin.get();
	return 0;
}