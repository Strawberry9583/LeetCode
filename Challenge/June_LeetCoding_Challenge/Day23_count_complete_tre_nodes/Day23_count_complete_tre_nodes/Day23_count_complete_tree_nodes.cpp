#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val) :val(val), left(nullptr), right(nullptr) {}
	TreeNode(int val, TreeNode* left, TreeNode* right) :val(val), left(left), right(right) {}
};

// solution1: normal recursion to traverse the tree;
// Time complexity: O(n); Space compexity: O(lgn);
class Solution1 {
	int m_count = 0;
public:
	int countNodes(TreeNode* root) {
		dfs(root);
		return m_count;
	}
	void dfs(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		else {
			++m_count;
			dfs(root->left);
			dfs(root->right);
		}
	}
};

// solution2: firstly, judge the hight of left_sub tree and right_sub tree;
// then return pow(2,height) if with equal height;
// otherwise, return recursive result;
// Time complexity: O(lgn*lgn) which is O(h+h-1+h-2...+1) and h is lgn, the height of the tree
// Space comlexity: O(lgn);
class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int left_height = 0, right_height = 0;
		TreeNode * left_sub = root->left, * right_sub = root->right;
		// calc the left_height and right_height;
		while (left_sub!=nullptr) {
			++left_height;
			left_sub = left_sub->left;
		}
		while (right_sub!=nullptr) {
			++right_height;
			right_sub = right_sub->right;
		}
		//left_height== right_height indicates the subtree is complete tree;
		if (left_height == right_height) { return 1 << left_height; }
		else {
			return 1 + countNodes(root->left) + countNodes(root->right);
		}
	}
};
int main() {
	cin.get();
	return 0;
}