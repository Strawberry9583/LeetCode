#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

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
	int m_sum = 0;
public:
	int sumRootToLeaf(TreeNode* root) {
		if (root == nullptr) {
			return m_sum;
		}
		string cur_path;
		traverse(root,cur_path);
		return m_sum;
	}
private:
	void traverse(TreeNode* root, string &cur_path) {
		cur_path += root->val+'0';
		if (root->left==nullptr&&root->right==nullptr) {
			// transfer the binary string into a integer;
			m_sum += stoi(cur_path,0,2);
		}
		else {
			if (root->left != nullptr) {
				traverse(root->left, cur_path);
			}
			if (root->right != nullptr) {
				traverse(root->right, cur_path);
			}
		}
		cur_path.pop_back();
	}
};

int main() {
	cin.get();
	return 0;
}