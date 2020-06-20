#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode * next = node->next;
		node->val = next->val;
		node->next = next->next;
		delete next;
		next = nullptr;
	}
};

int main() {
	cin.get();
	return 0;
}