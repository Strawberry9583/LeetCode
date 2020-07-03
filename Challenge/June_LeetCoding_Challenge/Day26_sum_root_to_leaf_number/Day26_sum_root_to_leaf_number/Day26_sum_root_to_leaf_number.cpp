#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val) :val(val), left(nullptr), right(nullptr) {}
	TreeNode(int val, TreeNode* left, TreeNode* right) :val(val), left(left), right(right) {}
};
// solution 1: DFS
class Solution1 {
	int m_sum = 0;
public:
	int sumNumbers(TreeNode* root) {
		if (root == nullptr) { return 0; }
		string cur_sum;
		traverse(root,cur_sum);
		return m_sum;
	}
	void traverse(TreeNode* root,string & cur_sum) {
		cur_sum+='0'+root->val;
		if (root->left==nullptr&& root->right==nullptr) {
			int cur_value = std::stoi(cur_sum);
			m_sum += cur_value;
		}
		if(root->left!=nullptr){
			traverse(root->left, cur_sum);
		}
		if (root->right != nullptr) {
			traverse(root->right, cur_sum);
		}
		cur_sum.pop_back();
	}
};

// solution2: DFS + avoid repeated calc of transferring string into numbers;
class Solution {
	int m_sum = 0;
public:
	int sumNumbers(TreeNode* root) {
		if (root == nullptr) { return 0; }
		int cur_sum = 0;
		traverse(root, cur_sum);
		return m_sum;
	}
	void traverse(TreeNode* root, int & cur_sum) {
		// instantly calc the cur_sum to avoid repeatly calc the numbers;
		cur_sum = cur_sum * 10 + root->val;
		if (root->left == nullptr&& root->right == nullptr) {
			m_sum += cur_sum;
		}
		if (root->left != nullptr) {
			traverse(root->left, cur_sum);
		}
		if (root->right != nullptr) {
			traverse(root->right, cur_sum);
		}
		// recover the previous situations.
		cur_sum /= 10;
	}
};

int main() {
	TreeNode node1(1), node2(2), node3(3);
	node1.left = &node2;
	node1.right = &node3;
	std::cout << Solution().sumNumbers(&node1) << std::endl;
	cin.get();
	return 0;
}