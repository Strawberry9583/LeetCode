//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//k is a positive integer and is less than or equal to the length of the linked list.If the number of nodes is not a multiple of k then left - out nodes in the end should remain as it is.
//
//Example:
//
//Given this linked list : 1->2->3->4->5
//
//For k = 2, you should return : 2->1->4->3->5
//
//For k = 3, you should return : 3->2->1->4->5

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>


using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 1||head==NULL) {
			return head;
		}
		ListNode temp(0);
		temp.next=head;

		pair<ListNode*, ListNode*> result= reverse_k(head, k);
		ListNode* front1 = result.first;
		ListNode* back1 = result.second;
		if (result.second == NULL) {
			return result.first;
		}
		ListNode* ans = result.first;

		while (back1->next!=NULL) {
			auto next = reverse_k(back1->next, k);
			if (next.first != NULL&&next.second!=NULL) {
				back1->next = next.first;
				back1 = next.second;
			}
			else {
				back1->next = next.first;
				break;
			}

		}
		return ans;
	}
	//reverse a length K list;
	pair<ListNode*,ListNode*> reverse_k(ListNode* head, int k) {
		if (head == NULL) {
			return make_pair(nullptr,nullptr);
		}
		size_t length = 0;
		//add a node for convenience;
		ListNode temp_node(0);
		temp_node.next = head;
		ListNode *temp = &temp_node;
		ListNode *front = temp;
		ListNode *back = temp->next;
		//cal the length of the list;
		while (back!=NULL) {
			++length;
			back = back->next;
			front = front->next;
		}
		//length < k, return the head and tail of the list;
		if (length < k) {
			return make_pair(temp->next, back);
		}
		// reverson k-1 times;
		//Principle: replace the head with back in every time;
		front = head;
		back = head->next;
		ListNode* back2 = back->next;
		for (size_t i = 0; i < k-1; ++i) {
			temp->next = back;
			back->next = front;
			front = temp->next;
			if (back2 != NULL) {
				back = back2;
				back2 = back2->next;
			}
			else {
				back = NULL;
			}
		}
		//if back2==NULL,then the K is the same as the length of the last part of the list;
		//if (back2 == NULL) {
		//	back = NULL;
		//}
		head->next = back;
		return make_pair(temp->next, head);
	}
};

int main() {
	ListNode node1(1), node2(2), node3(3), node4(4), node5(5), node6(6), node7(7);
	node1.next = &node2;
	//node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	//node5.next = &node6;
	node6.next = &node7;

	Solution sol;
	//auto temp=sol.reverse_k(&node1, 3);
	auto ans = sol.reverseKGroup(&node1, 2);
	while (ans!=NULL) {
		cout << ans->val << "  ";
		ans = ans->next;
	}
	cin.get();
	return 0;
}