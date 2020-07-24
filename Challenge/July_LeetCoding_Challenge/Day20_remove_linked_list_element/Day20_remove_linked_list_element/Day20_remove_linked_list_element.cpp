//**
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}    
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* cur = new ListNode(0, head);
		//record the dumb node to delete;
		ListNode* record2delete = cur;
		ListNode* ans = cur->next;
		//whether head is found;
		bool flag = false;
		while (cur->next != nullptr) {
			if (cur->next->val == val) {
				cur->next = cur->next->next;
			}
			else {
				//cur->next is the promising head;
				if (!flag) {
					flag = true;
					ans = cur->next;
				}
				cur = cur->next;
			}
		}
		//not found,then return nullptr;
		if (!flag) {
			ans = cur->next;
		}
		//delete dumb node;
		delete record2delete;
		return ans;
	}
};