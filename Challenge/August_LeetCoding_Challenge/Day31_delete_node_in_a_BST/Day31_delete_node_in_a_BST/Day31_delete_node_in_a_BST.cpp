#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//**
// * Definition for a binary tree node.
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
	 TreeNode* deleteNode(TreeNode* root, int key) {
		 auto find_ele = find_node(root, key);
		 if (find_ele == nullptr) {
			 return root;
		 }
		 else if (find_ele->left == nullptr&&find_ele->right == nullptr) {
			 if (find_ele == root) {
				 root = nullptr;
			 }
			 else {
				 reset_parent(root, find_ele);
				 find_ele = nullptr;
			 }
		 }
		 else if (find_ele->left != nullptr) {

			 auto max_val = max_node(find_ele->left);
			 reset_parent(find_ele, max_val);
			 find_ele->val = max_val->val;

			 max_val = nullptr;

		 }
		 else if (find_ele->right != nullptr) {
			 auto min_val = min_node(find_ele->right);
			 reset_parent(find_ele, min_val);
			 find_ele->val = min_val->val;

			 min_val = nullptr;
		 }
		 return root;
	 }
 private:
	 void reset_parent(TreeNode * root, TreeNode * target) {
		 if (root->left == target) {
			 root->left = target->left!=nullptr?target->left:target->right;
			 return;
		 }
		 else if (root->right == target) {
			 root->right = target->right!=nullptr?target->right:target->left;
			 return;
		 }
		 else {
			 if (root->val < target->val) {
				 reset_parent(root->right, target);
			 }
			 else {
				 reset_parent(root->left, target);
			 }
		 }
	 }
	 TreeNode* min_node(TreeNode *root) {
		 if (root->left == nullptr) {
			 return root;
		 }
		 else {
			 return min_node(root->left);
		 }
	 }
	 TreeNode* max_node(TreeNode * root) {
		 if (root->right == nullptr) {
			 return root;
		 }
		 else {
			 return max_node(root->right);
		 }
	 }

	 TreeNode* find_node(TreeNode* root, int key) {
		 if (root == nullptr) {
			 return nullptr;
		 }
		 else {
			 if (root->val == key) {
				 return root;
			 }
			 else if (root->val > key) {
				 return find_node(root->left, key);
			 }
			 else {
				 return find_node(root->right, key);
			 }
		 }
	 }
 };

 class Solution {
 public:
	 TreeNode* deleteNode(TreeNode* root, int key) {
		 if (!root)
			 return nullptr;

		 if (root->val == key) {
			 if (!root->right)
				 return root->left;
			 else {
				 TreeNode* n = root->right;
				 while (n->left)
					 n = n->left;
				 swap(n->val, root->val);

				 root->right = deleteNode(root->right, key);
				 return root;
			 }
		 }

		 if (root->val > key)
			 root->left = deleteNode(root->left, key);
		 if (root->val < key)
			 root->right = deleteNode(root->right, key);
		 return root;
	 }
 };
int main() {
	//TreeNode node1(5), node2(3), node3(6), node4(2), node5(4), node6(7);
	//node1.left = &node2; node1.right = &node3;
	//node2.left = &node4; node2.right = &node5;
	//node3.right = &node6;
	TreeNode node1(1), node2(2);
	node1.right = &node2;
	Solution().deleteNode(&node1, 1);
	cin.get();
	return 0;
}