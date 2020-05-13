#include<iostream>


using namespace std;

/**
* Definition for singly-linked list.*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		if (head == nullptr) {
			return head;
		}
		int length = 0;
		ListNode * cur = head;
		while (cur!=nullptr) {
			++length;
			cur = cur->next;
		}
		length /= 2;
		cur = head;
		for (int idx = 0; idx < length; ++idx) {
			cur = cur->next;
		}
		return cur;
	}
};

int main() {
	Solution sol;
	ListNode l1(1),l2(2),l3(3),l4(4),l5(5);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	auto cur=sol.middleNode(&l2);
	for (; cur != nullptr;) {
		std::cout << cur->val << "  ";
		cur = cur->next;
	}
	std::cin.get();
	return 0;
}