#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<functional>
#include<deque>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// with two queue to maintain the nodes of subsequent two level;
class Solution1 {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		std::vector<std::vector<int>> result;
		std::queue<TreeNode *> que_node; 
		if(root!=nullptr){ que_node.emplace(root); }
		while (!que_node.empty()) {
			std::vector<int> temp_vec;
			std::queue<TreeNode *> temp_que;
			while (!que_node.empty()) {
				auto temp_node = que_node.front(); que_node.pop();
				temp_vec.emplace_back(temp_node->val);
				if (temp_node->left != nullptr) { temp_que.emplace(temp_node->left); }
				if (temp_node->right != nullptr) { temp_que.emplace(temp_node->right); }
			}
			que_node = std::move(temp_que);
			//result.emplace(result.begin(),std::move(temp_vec));
			result.emplace_back(std::move(temp_vec));
		}
		reverse(result.begin(),result.end());
		return result;
	}
};

// use an interge to record the nodes number of the last level;
// and replace the queue adaptor with deque;
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		std::vector<std::vector<int>> result;
		std::deque<TreeNode *> que_node;
		if (root != nullptr) { que_node.emplace_back(root); }
		while (!que_node.empty()) {
			std::vector<int> temp_vec;
			int node_num = que_node.size();
			while (node_num>0) {
				--node_num;
				auto temp_node = que_node.front(); que_node.pop_front();
				temp_vec.emplace_back(temp_node->val);
				if (temp_node->left != nullptr) { que_node.emplace_back(temp_node->left); }
				if (temp_node->right != nullptr) { que_node.emplace_back(temp_node->right); }
			}
			result.emplace_back(std::move(temp_vec));
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

int main() {

	cin.get();
	return 0;
}