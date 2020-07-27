#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

struct TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

// solution 1: use stack to find the parrent node;
// Time complexity: O(n); Space complexity: O(n);
// the method the find the parrent of cur_node;
// find the cur_node is btwn [node1, node2], in which the node2 is the parrent of node1;
// then the cur_node if the left child or the right child of node1;
class Solution {
public:
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		if(preorder.empty()) {
			return nullptr;
		}
		TreeNode * result = new TreeNode(preorder[0]);
		std::stack<TreeNode*> sta;
		sta.emplace(result);
		int cur_idx = 1;
		while (cur_idx<preorder.size()) {
			auto top = sta.top();
			//record the root;
			while ((!sta.empty())&&sta.top()->val<preorder[cur_idx]) {
				top = sta.top();
				sta.pop();
			}
			//set the left child of root;
			if (top->val > preorder[cur_idx]) {
				top->left = new TreeNode(preorder[cur_idx]);
				sta.emplace(top->left);
			}
			//set the right child of root;
			else{
				top->right = new TreeNode(preorder[cur_idx]);
				sta.emplace(top->right);
			}
			++cur_idx;
		}
		return result;
	}
};

// Solution2: DC to construct left child tree and right child tree respectively;
// Time complexity: O(n*logn); Sapce compelxity: O(logH), H is the height of the tree;
class Solution2 {
public:
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		if (preorder.empty()) {
			return NULL;
		}
		return build_BST(0, preorder.size() - 1, preorder);
	}
	TreeNode* build_BST(int start, int end, std::vector<int> nums) {
		if (end == start) {
			TreeNode * node = new TreeNode(nums[start]);
			return node;
		}
		else if (start>end) {
			return NULL;
		}
		else {
			TreeNode *node = new TreeNode(nums[start]);
			int idx = start + 1;
			for (; idx <= end; ) {
				if (nums[idx] < nums[start]) {
					++idx;
				}
				else {
					break;
				}
			}
			node->left = build_BST(start + 1, idx - 1, nums);
			node->right = build_BST(idx, end, nums);
			return node;
		}
	}
};

int main() {

	cin.get();
	return 0;
}