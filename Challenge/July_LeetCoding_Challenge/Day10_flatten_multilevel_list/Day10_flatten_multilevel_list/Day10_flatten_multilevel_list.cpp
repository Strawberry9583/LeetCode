#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;



// Definition for a Node.
class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;
};


class Solution {
public:
	Node* flatten(Node* head) {
		if (head != nullptr) {
			dfs(head);
		}
		return head;
	}
	// return the last non-null node;
	Node * dfs(Node* cur_node) {
		if (cur_node->child != nullptr) {
			Node* next = cur_node->next;
			Node* child = cur_node->child;
			// get the last non-null node;
			Node* children_end = dfs(child);
			// reset next;
			cur_node->next = child;
			// set child to null;
			cur_node->child = nullptr;
			child->prev = cur_node;
			if (next != nullptr) {
				next->prev = children_end;
				children_end->next = next;
				return dfs(next);
			}
			else {
				return children_end;
			}
		}
		//return the end node;
		else if (cur_node->next == nullptr) {
			return cur_node;
		}
		else {
			return dfs(cur_node->next);
		}
	}
};

int main() {
	cin.get();
	return 0;
}