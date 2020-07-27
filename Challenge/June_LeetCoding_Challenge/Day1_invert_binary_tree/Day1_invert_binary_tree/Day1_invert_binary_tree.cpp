#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val) :val(val), left(nullptr), right(nullptr) {}
	TreeNode(int val, TreeNode* left, TreeNode*right) :val(val), left(left), right(right) {}
};

// solution 1: queue based BFS;
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr) {
			return nullptr;
		}
		std::queue<TreeNode*> que_node;
		que_node.emplace(root);
		while (!que_node.empty()) {
			auto top = que_node.front(); que_node.pop();
			auto temp = top->left;
			top->left = top->right;
			top->right = temp;
			if (top->left != nullptr) {
				que_node.emplace(std::move(top->left));
			}
			if (top->right != nullptr) {
				que_node.emplace(move(top->right));
			}
		}
		return root;
	}

};

// solution 2: recursion:
class Solution2 {
public:
	TreeNode* invertTree(TreeNode* root) {
		invert(root);
		return root;
	}
	void invert(TreeNode *root) {
		if (root == nullptr) {
			return;
		}
		TreeNode * temp = root->left;
		root->left = root->right;
		root->right = temp;
		invert(root->left);
		invert(root->right);
	}
};

int main() {

	cin.get();
	return 0;
}