#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
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
	TreeNode * left;
	TreeNode * right;
	TreeNode():val(0), left(nullptr), right(nullptr){}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode * left, TreeNode * right) :val(x), left(left), right(right) {}
};

class Solution1 {
private:
	std::unordered_map<TreeNode *, int> m_node2max;
	int m_result;
public:
	int maxPathSum(TreeNode* root) {
		m_result = std::numeric_limits<int>::lowest();
		traverse(root);
		m_node2max[nullptr] = 0;
		return m_result;
	}
	void traverse(TreeNode * root) {
		if (root == nullptr) {
			return;
		}
		else {
			max_path(root);
			traverse(root->left);
			traverse(root->right);
		}
	}
	int max_path(TreeNode * node) {
		if (node == nullptr) {
			return 0;
		}
		auto find_max = m_node2max.find(node);
		if (find_max!=m_node2max.end()) {
			return find_max->second;
		}
		else {
			int left_max = max_path(node->left);
			int right_max = max_path(node->right);
			m_node2max[node] = node->val + std::max({ left_max, right_max,0 });

			int cur_node_max_path = std::max({ left_max + right_max + node->val, node->val,
				left_max + node->val,right_max + node->val });
			if (cur_node_max_path> m_result) {
				m_result = cur_node_max_path;
			}
			return m_node2max[node];
		}
	}
};


class Solution {
private:
	std::unordered_map<TreeNode *, int> m_node2max;
	int m_result;
public:
	int maxPathSum(TreeNode* root) {
		m_result = std::numeric_limits<int>::lowest();
		max_path(root);
		return m_result;
	}
	//find the max path of starting with root;
	int max_path(TreeNode * root) {
		if (root == nullptr) {
			return 0;
		}
		else {
			int left_max = std::max(max_path(root->left),0);
			int right_max = std::max(max_path(root->right),0);
			int max_leaf_path = std::max(left_max, right_max);
			//root as the center point; 
			//then add left_max_path and right_max_path to compare with result;
			int cur_result = left_max+right_max +root->val;
			if (cur_result > m_result) {
				m_result = cur_result;
			}
			return max_leaf_path+root->val;
		}
	}
};
int main() {
	Solution sol;
	TreeNode node1(2), node2(1), node3(3);
	node1.left = &node2;
	node1.right = &node3;
	std::cout << sol.maxPathSum(&node1);
	std::cin.get();
	return 0;
}