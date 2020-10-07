#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

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
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr||k==0) {
			return head;
		}
		int length = 0;
		auto temp = head;
		while (temp!=nullptr) {
			++length;
			temp = temp->next;
		}
		k %= length;
		ListNode node; node.next = head;
		ListNode* pre = &node,* cur = &node;
		int dis = 0;
		while (cur->next!=nullptr) {
			if (dis == k) {
				pre = pre->next;
			}
			cur = cur->next;
			if (dis < k) {
				++dis;
			}
		}
		cur->next = head;
		auto result = pre->next;
		pre->next = nullptr;
		return result;
	}
};

int main() {
	cin.get();
	return 0;
}