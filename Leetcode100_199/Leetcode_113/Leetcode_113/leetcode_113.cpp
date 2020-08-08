#include<iostream>
#include<vector>

using namespace std;

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };



  // path sum II
  //Given a binary tree and a sum, find all root - to - leaf paths where each path's sum equals the given sum.

	 // Note: A leaf is a node with no children.

	 // Example :

	 // Given the below binary tree and sum = 22,

	 // 5
	 // / \
	 // 4   8
	 // /   / \
	 // 11  13  4
	 // / \ / \
	 // 7    2  5   1
	 // Return:

  //[
	 // [5, 4, 11, 2],
	 // [5, 8, 4, 5]
  //]
class Solution {
	std::vector<std::vector<int>> m_result;
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (root == nullptr) {
			return m_result;
		}
		std::vector<int> path;
		dfs(root, path, 0, sum);
		return m_result;
	}

private:
	void dfs(TreeNode * root, std::vector<int> & path, int cur_sum, int sum) {
		if (root == nullptr) {
			return;
		}
		path.emplace_back(root->val);
		cur_sum += root->val;
		if (root->left == nullptr&& root->right == nullptr&&cur_sum==sum) {
			m_result.emplace_back(path);
			path.pop_back();
			return;
		}
		else {
			dfs(root->left, path, cur_sum, sum);
			dfs(root->right, path, cur_sum, sum);
			//recover the previous status;
			path.pop_back();
			cur_sum -= root->val;
		}
	}
};

int main() {
	cin.get();
	return 0;
}