#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>

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

// find the root fistly, then construct left and right tree respectively;
// time complexity£º O(n*lgn)
class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		auto root=construct_tree( inorder, 0, inorder.size(),postorder,
			0, postorder.size());
		return root;
	}
	TreeNode* construct_tree(vector<int>& inorder, int in_left, int in_right, vector<int>&postorder,
		int post_left, int post_right) {
		TreeNode * root = new TreeNode();
		if (in_left+1 == in_right) {
			root->val = postorder[post_left];
			return root;
		}
		else if (in_left == in_right) {
			return nullptr;
		}
		root->val = postorder[post_right-1];
		int idx = in_left;
		for (; idx < in_right; ++idx) {
			if (inorder[idx] == root->val) {
				break;
			}
		}
		root->left = construct_tree(inorder, in_left, idx, postorder, post_left, post_left + (idx - in_left));
		root->right = construct_tree(inorder, idx + 1, in_right, postorder, post_left + (idx - in_left), post_right - 1);
		return root;
	}
};

// find the root fistly, then construct left and right tree respectively;
// time complexity£º O(n) use hash_map to record the idx match up of inorder and postorder sequence;
class Solution2 {
	std::unordered_map<int, int> m_postidx2inidx;
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		std::unordered_map<int, int> inorderval2idx;
		for (int idx = 0; idx < inorder.size(); ++idx) {
			inorderval2idx[inorder[idx]] = idx;
		}
		for (int post_idx = 0; post_idx < postorder.size(); ++post_idx) {
			m_postidx2inidx[post_idx] = inorderval2idx[postorder[post_idx]];
		}
		auto root = construct_tree(inorder, 0, inorder.size(), postorder,
			0, postorder.size());
		return root;
	}
	TreeNode* construct_tree(vector<int>& inorder, int in_left, int in_right, vector<int>&postorder,
		int post_left, int post_right) {
		TreeNode * root = new TreeNode();
		if (in_left + 1 == in_right) {
			root->val = postorder[post_left];
			return root;
		}
		else if (in_left == in_right) {
			return nullptr;
		}
		root->val = postorder[post_right - 1];
		// find the idx according to the pre-calculated map;
		int idx = m_postidx2inidx[post_right - 1];
		// recursively construct the tree;
		root->left = construct_tree(inorder, in_left, idx, postorder, post_left, post_left + (idx - in_left));
		root->right = construct_tree(inorder, idx + 1, in_right, postorder, post_left + (idx - in_left), post_right - 1);
		return root;
	}
};


int main() {

	cin.get();
	return 0;
}