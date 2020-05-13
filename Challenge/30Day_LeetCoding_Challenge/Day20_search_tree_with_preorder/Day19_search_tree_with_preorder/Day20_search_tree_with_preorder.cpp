#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}

};
//solution 1: time complexity: O(nlongn); space complexity: O(1);
class Solution1 {
public:
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		if (preorder.empty()) {
			return NULL;
		}
		return build_BST(0, preorder.size()-1, preorder);
	}
	//build range [start,end] in nums;
	//first find root then construc the left_tree and then build the right_tree recurisively.
	TreeNode* build_BST(int start, int end, std::vector<int> nums) {
		if (end==start) {
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
			node->left = build_BST(start + 1, idx-1, nums);
			node->right = build_BST(idx, end, nums);
			return node;
		}
	}
};

//use stack to store the intermidiate left root until find the right root,
//which have greater value than the stack top;
//Time complexity: O(n);
//Space complexity: O(n);
class Solution {
public:
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		if (preorder.empty()) {
			return NULL;
		}
		std::stack<TreeNode*> stk;
		auto result = new TreeNode(preorder[0]);
		stk.emplace(result);
		for (int idx = 1; idx < preorder.size(); ++idx) {
			auto top = stk.top();
			//find the root;
			while ((!stk.empty())&&stk.top()->val<preorder[idx]) {
				top = stk.top();
				stk.pop();			
			}
			if (top->val > preorder[idx]) {
				top->left = new TreeNode(preorder[idx]);
				stk.emplace(top->left);
			}
			else {
				top->right = new TreeNode(preorder[idx]);
				stk.emplace(top->right);
			}

		}
		return result;
	}
};

int main() {
	std::vector<int> test_nums{ 8,5,1,7,10,12 };
	auto ans = Solution().bstFromPreorder(test_nums);

	std::cin.get();
	return 0;
}