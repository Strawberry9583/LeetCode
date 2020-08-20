#include<vector>
#include<iostream>

using namespace std;


 // Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// store the listnode with vector then reorder the listnode;
// time complexity: O(n), space complexity: O(n);
class Solution1 {
public:
	void reorderList(ListNode* head) {
		std::vector<ListNode*> all_node;
		ListNode* cur = head;
		while (cur!=nullptr) {
			all_node.emplace_back(cur);
			cur = cur->next;
		}
		int first = 0, second = all_node.size() - 1;
		while (first<second){
			all_node[first]->next = all_node[second];
			all_node[second]->next = first + 1 < second ? all_node[first + 1] : nullptr;
			++first; --second;
		}
		if (first == second) {
			all_node[first]->next = nullptr;
		}
	}
};

// solution2: split the list into two half and reverse the second half, then mrege the  two list;
// time complexity: O(n), space complexity: O(1);
class Solution {
public:
	void reorderList(ListNode* head) {
		// Check edge case
		if (head == NULL) return;

		ListNode *cur1, *cur2, *prev, *next1, *next2;
		int n = 0;

		// Count the number of nodes => O(N)
		cur1 = head;
		while (cur1) {
			n++;
			cur1 = cur1->next;
		}

		// Found middle node => O(N/2)
		n = n / 2;
		cur1 = head;
		for (int i = 0; i < n; i++) {
			prev = cur1;
			cur1 = cur1->next;
		}

		// set NULL to last node of first half
		next1 = cur1->next;
		cur1->next = NULL;
		cur1 = next1;
		prev = NULL;

		// Reverse second half : 4->5->6 => 6->5->4 => O(N/2)
		while (cur1) {
			next1 = cur1->next;
			cur1->next = prev;
			prev = cur1;
			cur1 = next1;
		}

		// Link first half and second half => O(N/2)
		cur1 = head;
		cur2 = prev;

		while (cur1 && cur2) {
			next1 = cur1->next;
			cur1->next = cur2;
			next2 = cur2->next;
			cur2->next = next1;
			cur1 = next1;
			cur2 = next2;
		}
		return;
	}
};

int main() {
	cin.get();
	return 0;
}