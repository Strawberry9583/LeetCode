//Given a linked list, remove the n - th node from the end of list and return its head.
//
//Example:
//
//Given linked list : 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>


using namespace std;



// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//method 1: use map to restore the List; then visite the expected element; next erase the Nth from the end;
	//ListNode* removeNthFromEnd(ListNode* head, int n) {
	//	ListNode *ptr = head;
	//	map<int, ListNode *> result;
	//	int num = 0;
	//	while (ptr!=NULL) {
	//		++num;
	//		ListNode* temp = ptr;
	//		result.insert(std::make_pair(num,temp));
	//		ptr = ptr->next;
	//	}
	//	if (result.size() == 1) {
	//		return NULL;
	//	}
	//	if (result.size() == n) {
	//		return result[0]->next;
	//	}
	//	else {
	//		result[result.size() - n]->next = result[result.size() - n + 2];
	//		return head;
	//	}

	//Method 2:
	//Maintain two pointers and update one with a delay of n steps.
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* fast = head, **slow = &head;

		while (n--) fast = fast->next;

		while (fast) {
			fast = fast->next;
			slow = &(*slow)->next;
		}

		*slow = (*slow)->next;
		return head;
	}
	}
};


int main() {
	ListNode n5(5), n4(4), n3(3), n2(2), n1(1);
	n4.next = &n5;
	n3.next = &n4;
	n2.next = &n3;
	n1.next = &n2;
	ListNode n11(1);

	Solution sol;
	ListNode* result=sol.removeNthFromEnd(&n11,1);
	//while (result!=NULL) {
	//	cout << result->val << "  ";
	//	result = result->next;
	//}

	cin.get();
	return 0;
}