#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution1 {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL) {
			return NULL;
		}
		//calc the length of the list;
		ListNode * cur = head->next;
		int lenght = 1;
		while (cur!=NULL) {
			++lenght;
			cur = cur->next;
		}
		//the shift k is equal to k%length shift;
		if (k >= lenght) {
			k = k%lenght;
		}
		if (k == 0) {
			return head;
		}
		ListNode * new_head(head);
		cur = head;
		int distance = 0;
		//get the last k+1 node;
		while (cur->next!=NULL) {
			cur = cur->next;
			if (distance >= k) {
				new_head = new_head->next;
			}
			++distance;
		}
		cur->next = head;
		head = new_head->next;
		new_head->next = NULL;
		return head;
	}
};

//solution 2: build a circle then find the k_th node with the start of last node;
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) {
			return NULL;
		}

		// go to tail
		ListNode* tail = head;
		int size = 1;
		while (tail->next) {
			tail = tail->next;
			++size;
		}

		// build a circle
		tail->next = head;

		// go to the new tail and cut the circle
		int n = size - k % size;
		while (n--) {
			tail = tail->next;
		}
		head = tail->next;
		tail->next = NULL;

		return head;
	}
};

int main() {
	Solution sol;
	ListNode node1(1), node2(2), node3(3), node4(4), node5(5);
	node1.next = &node2;
	//node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	auto ans = sol.rotateRight(&node1, 2);
	std::cin.get();
	return 0;
}