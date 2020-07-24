#include<queue>
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		std::vector<std::vector<int>> result;
		std::deque<TreeNode *> que_node;
		if (root != nullptr) { que_node.emplace_back(root); }
		bool flag = true;
		while (!que_node.empty()) {
			std::vector<int> temp_vec;
			int node_num = que_node.size();
			while (node_num>0) {
				--node_num;
				auto temp_node = que_node.front(); que_node.pop_front();
				if (flag) { temp_vec.emplace_back(temp_node->val); }
				else { temp_vec.emplace(temp_vec.begin(), temp_node->val); }
				if (temp_node->left != nullptr) { que_node.emplace_back(temp_node->left); }
				if (temp_node->right != nullptr) { que_node.emplace_back(temp_node->right); }
			}
			flag = !flag;
			result.emplace_back(std::move(temp_vec));
		}
		//reverse(result.begin(), result.end());
		return result;
	}
};





int main() {
	std::cout << MajorityChecker(std::vector<int>{1, 1, 2, 2, 1, 1}).query(2, 3, 2);
	cin.get();
	return 0;
}