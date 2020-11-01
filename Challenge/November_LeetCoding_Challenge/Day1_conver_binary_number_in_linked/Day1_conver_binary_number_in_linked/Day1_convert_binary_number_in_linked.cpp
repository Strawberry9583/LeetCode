#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;



//* Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
	int getDecimalValue(ListNode* head) {
		int result = 0;
		auto cur_node = head;
		while (cur_node!=nullptr) {
			result <<= 1;
			result += cur_node->val;
			cur_node = cur_node->next;
		}
		return result;
	}
};

int main() {
	ListNode node1(1), node2(0), node3(1);
	node1.next = &node2;
	node2.next = &node3;
	std::cout << Solution().getDecimalValue(&node1);
	cin.get();
	return 0;
}