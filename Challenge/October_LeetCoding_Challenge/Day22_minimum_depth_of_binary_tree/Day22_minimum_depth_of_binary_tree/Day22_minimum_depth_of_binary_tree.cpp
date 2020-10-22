#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



 // Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution1 {	
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int cur_node_num = 1;
		return min_node_number(cur_node_num, root);
	}
private:
	int min_node_number(int cur_node_num, TreeNode * cur_node) {
		if (cur_node->left==nullptr&&cur_node->right==nullptr) {
			return cur_node_num;
		}
		else if(cur_node->left==nullptr) {
			return min_node_number(cur_node_num + 1, cur_node->right);
		}
		else if (cur_node->right == nullptr) {
			return min_node_number(cur_node_num + 1, cur_node->left);
		}
		else {
			return std::min(min_node_number(cur_node_num + 1, cur_node->left), \
				min_node_number(cur_node_num + 1, cur_node->right));
		}
	}
};


class Solution {
public:
	int ans = INT_MAX;
	void calc(TreeNode* root, int dep = 0) {
		if (root == NULL)
			return;
		if (root->left)
			calc(root->left, dep + 1);
		if (root->right)
			calc(root->right, dep + 1);
		if (!root->left && !root->right) {
			ans = min(ans, dep + 1);
			return;
		}
	}
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		calc(root);
		return ans;
	}
};

int main() {
	cin.get();
	return 0;
}