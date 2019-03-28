//Merge k sorted linked lists and return it as one sorted list.Analyze and describe its complexity.
//
//Example:
//
//Input:
//[
//	1->4->5,
//	1->3->4,
//	2->6
//]
//Output : 1->1->2->3->4->4->5->6



#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

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
		while (l1 != NULL&&l2 != NULL) {
			if (l1->val < l2->val) {
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
	
	ListNode * mergeKLists(vector<ListNode*> & lists) {
		if (lists.empty()) {
			return NULL;
		}
		if (lists.size() == 1) {
			return lists[0];
		}
		while (lists.size()!=1) {
			//size_num is odd; calculate the pair num of the lists;
			size_t pair_num = lists.size() / 2;
			//size_num is even;
			if (lists.size() & 1 == 1) {
				++pair_num;
			}
			vector<ListNode*> vec_list;
			for (size_t i = 0; i < pair_num; ++i) {
				if ((i==pair_num-1)&&(lists.size()&1==1)) {
					vec_list.push_back(*lists.rbegin());
					break;
				}
				//select two list to sort;
				size_t idx_left = 2 * i, idx_right = idx_left + 1;
				vec_list.push_back(mergeTwoLists(lists[idx_left], lists[idx_right]));
			}
			lists = vec_list;
		}
		return lists[0];
	}
};


int main() {
	Solution sol;
	ListNode node1(1), node2(4), node3(5), node4(1), node5(3), node6(4), node7(2), node8(6);
	node1.next = &node2;
	node2.next = &node3;
	node4.next = &node5;
	node5.next = &node6;
	node7.next = &node8;
	vector<ListNode*>test{ &node1,&node4,&node7 };
	auto ans = sol.mergeKLists(test);
	while (ans!=NULL) {
		cout << ans->val << "  ";
		ans = ans->next;
	}
	cin.get();
	return 0;
}