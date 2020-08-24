#include<iostream>
#include<algorithm>
#include<vector>

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

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		int sum = 0;
		if (root == nullptr) {
			return 0;
		}
		int flag = -1;
		traverse(root, sum, flag);
		return sum;
	}
private:
	void traverse(TreeNode* root, int & sum, int flag) {
		if (root == nullptr) {
			return;
		}
		if (root->left == nullptr&&root->right == nullptr) {
			if (flag == 0) {
				sum += root->val;
			}
			else {
				return;
			}
		}
		if(root->left!=nullptr) {
			traverse(root->left, sum, 0);
		}
		if (root->right != nullptr) {
			traverse(root->right, sum, 1);
		}
	}
};

int main() {
	cin.get();
	return 0;
}