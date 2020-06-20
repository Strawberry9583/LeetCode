#include<vector>
#include<string>
#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode*left, TreeNode*right) :val(x), left(left), right(right) {}
};

// solution1: recursion method
class Solution1 {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == nullptr) {
			return NULL;
		}
		else {
			if (root->val == val) {
				return root;
			}
			else if (root->val > val) {
				return searchBST(root->left, val);
			}
			else {
				return searchBST(root->right, val);
			}
		}
	}
};

// solution2: non-recursive method
class Solution {
public:

	TreeNode* searchBST(TreeNode* root, int val) {
		// TreeNode *t=root;
		while (root) {
			if (val == root->val)
				return root;
			else if (val<root->val)
				root = root->left;
			else //if(val>root->val)
				root = root->right;
		}
		return NULL;
	}
};

int main() {

	cin.get();
	return 0;
}