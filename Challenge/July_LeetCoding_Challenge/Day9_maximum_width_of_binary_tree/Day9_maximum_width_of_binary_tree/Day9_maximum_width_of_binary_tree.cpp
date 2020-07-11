#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// level order traverse when encountering nullptr, push two nullptr into the level;
class Solution1 {
public:
	int widthOfBinaryTree(TreeNode* root) {
		std::deque<TreeNode*> deq;
		if (root != nullptr) {
			deq.emplace_back(root);
		}
		int result = deq.size();
		while (!deq.empty()) {
			int pre_size = deq.size();
			for (int idx = 0; idx < pre_size; ++idx) {
				auto temp = deq.front();
				if (temp != nullptr) {
					deq.emplace_back(temp->left);
					deq.emplace_back(temp->right);
				}
				// when encountering nullptr, push two nullptr
				else {
					deq.emplace_back(nullptr);
					deq.emplace_back(nullptr);
				}
				deq.pop_front();
			}
			while ((!deq.empty()) && deq.front() == nullptr) {
				deq.pop_front();
			}
			while ((!deq.empty()) && deq.back() == nullptr) {
				deq.pop_back();
			}
			if (deq.size() > result) {
				result = deq.size();
			}
		}
		return result;
	}
};

// solution 2:
// just store and the idx to avoid frequently push nullptr nodes;
class Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		std::deque<std::pair<TreeNode*, long long unsigned int>> deq;
		if (root != nullptr) {
			deq.emplace_back(root, 0);
		}
		long long int result = deq.size();
		while (!deq.empty()) {
			int pre_size = deq.size();
			for (int idx = 0; idx < pre_size; ++idx) {
				auto temp = deq.front(); deq.pop_front();
				if (temp.first->left != nullptr) {
					deq.emplace_back(temp.first->left, temp.second * 2 + 1);
				}
				if (temp.first->right != nullptr) {
					deq.emplace_back(temp.first->right, temp.second * 2 + 2);
				}
			}
			if ((!deq.empty()) && result < deq.back().second - deq.front().second + 1) {
				result = deq.back().second - deq.front().second + 1;
			}
		}
		return result;
	}
};

int main() {
	TreeNode node1(1), node2(3), node3(2), node4(5), node5(3), node6(9);
	node1.left = &node2; node1.right = &node3; node2.left = &node4;
	node2.right = &node5; node3.right = &node6;
	std::cout << Solution().widthOfBinaryTree(&node1);
	cin.get();
	return 0;
}