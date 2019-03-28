//Merge two sorted linked lists and return it as a new list.The new list should be made by splicing together the nodes of the first two lists.
//
//Example:
//
//Input: 1->2->4, 1->3->4
//	Output : 1->1->2->3->4->4

#include<iostream>
#include<vector>
#include<algorithm>



using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//iterative method;
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode * result = new ListNode(1);//ctr the head node for uniform following operation;
		ListNode * final_reuslt = result;
		while (l1!=NULL&&l2!=NULL) {
			if (l1->val < l2->val){
				//show the use of the head node;
				result->next = l1;
				l1 = l1->next;
				result = result->next;
			}
			else {
				result->next = l2;
				l2 = l2->next;
				result = result->next;
			}

		}
		if (l1 != NULL) {
			result->next = l1;
		}
		else if (l2 != NULL) {
			result->next = l2;
		}
		return final_reuslt->next;

	}
	//recurtive method;
	//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	//	ListNode* merged = NULL;
	//	if (l1 == NULL) {
	//		return l2;
	//	}
	//	else if (l2 == NULL) {
	//		return l1;
	//	}
	//	else if (l1->val < l2->val) {
	//		merged = new ListNode(l1->val);
	//		merged->next = mergeTwoLists(l1->next, l2);
	//	}
	//	else {
	//		merged = new ListNode(l2->val);
	//		merged->next = mergeTwoLists(l1, l2->next);
	//	}
	//	return merged;
	//}

};


int main() {
	ListNode l1(1), l2(2), l3(4);
	ListNode l4(1), l5(3), l6(4);
	l1.next = &l2;
	l2.next = &l3;
	l4.next = &l5;
	l5.next = &l6;
	Solution sol;
	auto result = sol.mergeTwoLists(&l1, &l4);
	while (result!=NULL) {
		cout << result->val << "  ";
		result = result->next;
	}


	cin.get();
	return 0;
}