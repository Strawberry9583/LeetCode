#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


 //* Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		insert_value(root, val);
		return root;
	}
private:
	void insert_value(TreeNode * & root, int val) {
		if (root == nullptr) {
			root = new TreeNode(val);
		}
		else {
			if (root->val > val) {
				insert_value(root->left, val);
			}
			else {
				insert_value(root->right, val);
			}
		}
	}
};

int main() {
	TreeNode node1(4), node2(2), node3(7), node4(1), node5(3);
	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	Solution().insertIntoBST(&node1, 5);
	cin.get();
	return 0;
}