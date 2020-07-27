#include<iostream>
#include<vector>
#include<stack>
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
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode*left, TreeNode *right) :val(x), left(left), right(right) {}
};

//Solution1: in BST, the pre_order traverse is from the smallest to the biggest one;
class Solution {
	int m_result;
public:
	int kthSmallest(TreeNode* root, int k) {
		int cur = 0;
		inorder_traversal(root, k, cur);
	}
	//return the amout of num < root;
	void inorder_traversal(TreeNode* root, int k,int & cur) {
		if (root == nullptr) {
			return;
		}
		else {
			inorder_traversal(root->left, k, cur);
			++cur;
			if (cur == k) {
				m_result = root->val;
				return;
			}
			inorder_traversal(root->right, k, cur);
		}
	}
};
// Solution2: in BST, the pre_order traverse is from the smallest to the biggest one;
// but use the stack instead of the recursion;
class Solution2 {
public:
	int kthSmallest(TreeNode* root, int k) {
		int cnt = 0;
		stack<TreeNode*> s;
		TreeNode *p = root;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			p = s.top(); s.pop();
			++cnt;
			if (cnt == k) return p->val;
			p = p->right;
		}
		return 0;
	}
};

int main() {

	cin.get();
	return 0;
}