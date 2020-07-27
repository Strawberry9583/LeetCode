#include<iostream>

using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr||head->next==nullptr) {
			return head;
		}
		ListNode* odd_end = head;
		ListNode* even_end = head->next;
		ListNode* even_start = head->next;
		ListNode* cur = even_end->next;
		even_end->next = nullptr;
		bool odd = true;
		while (cur) {
			ListNode* temp = cur->next;
			if (odd) {
				cur->next = even_start;
				odd_end->next = cur;
				odd_end = cur;
				cur = temp;
				odd = false;
			}
			else {
				cur->next = nullptr;
				even_end->next=cur;
				cur = temp;
				odd = true;
			}
		}
		return head;
	}
};

int main() {

	cin.get();
	return 0;
}