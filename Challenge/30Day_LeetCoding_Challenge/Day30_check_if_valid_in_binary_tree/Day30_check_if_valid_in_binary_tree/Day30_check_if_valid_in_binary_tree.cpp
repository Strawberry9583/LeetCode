#include<iostream>
#include<vector>
#include<string>

using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) :val(val), left(left), right(right) {}
};

class Solution {
public:
	bool isValidSequence(TreeNode* root, vector<int>& arr) {
		return is_valid(root, arr, 0);
	}
	bool is_valid(TreeNode * root, std::vector<int>& arr, int cur_idx) {
		if (cur_idx == arr.size()-1 ) {
			if (root!=nullptr&&arr.back()==root->val&&\
				root->left==nullptr&&root->right==nullptr) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			if (root->val == arr[cur_idx]) {
				return is_valid(root->left, arr, cur_idx + 1) || is_valid(root->right, arr, cur_idx + 1);
			}
			else {
				return false;
			}
		}
	}
};

int main() {
	Solution sol;
	TreeNode node1(0), node2(1), node3(0), node4(0), node5(1), node6(0), node7(1), node8(0), node9(0);
	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	node3.left = &node6;
	node4.right = &node7;
	node5.left = &node8;
	node5.right = &node9;
	std::cout << sol.isValidSequence(&node1, std::vector<int>{0, 1, 0, 1});
	std::cin.get();
	return 0;
}