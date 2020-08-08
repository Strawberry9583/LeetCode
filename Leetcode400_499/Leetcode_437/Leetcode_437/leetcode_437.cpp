#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;



// * Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// method1: traverse all nodes, calc all sum frequency with itself as root; (down-top)
// store the sum frequency with unodered_map;
class Solution1 {
	int m_result = 0;
	int m_sum = 0;
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == nullptr) {
			return m_result;
		}
		m_sum = sum;
		calc_sum(root);
		return m_result;
	}
private:
	std::unordered_map<int, int> calc_sum(const TreeNode* root) {
		std::unordered_map<int, int> num2freq;

		if (root != nullptr) {
			++num2freq[root->val];
			if (root->left != nullptr) {
				auto left = calc_sum(root->left);
				for (auto & ele : left) {
					num2freq[ele.first + root->val] += ele.second;
				}
			}
			if (root->right != nullptr) {
				auto right = calc_sum(root->right);
				for (auto & ele : right) {
					num2freq[ele.first + root->val] += ele.second;
				}
			}
		}
		else {
			num2freq[0] = 1;
		}
		m_result += num2freq[m_sum];
		return num2freq;
	}
};

// method2: similar to solution1 but with map to record sum frequency; (down-top)
class Solution2 {
	int m_result = 0;
	int m_sum = 0;
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == nullptr) {
			return m_result;
		}
		m_sum = sum;
		calc_sum(root);
		return m_result;
	}
private:
	std::map<int, int> calc_sum(const TreeNode* root) {
		std::map<int, int> num2freq;

		if (root != nullptr) {
			++num2freq[root->val];
			if (root->left != nullptr) {
				auto left = calc_sum(root->left);
				for (auto & ele : left) {
					num2freq[ele.first + root->val] += ele.second;
				}
			}
			if (root->right != nullptr) {
				auto right = calc_sum(root->right);
				for (auto & ele : right) {
					num2freq[ele.first + root->val] += ele.second;
				}
			}
		}
		else {
			num2freq[0] = 1;
		}
		m_result += num2freq[m_sum];
		return num2freq;
	}
};

// method: dfs + memorization; (top-down)

class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		// record all path sum from the starting root;
		unordered_map<int, int> map;
		return dfs(root, 0, sum, map);
	}
private:
	int dfs(TreeNode* curr, int path, int sum, unordered_map<int, int>& map) {
		if (curr == nullptr) return 0;

		//update the current path staring from root to current node;
		path += curr->val;

		int num_results = 0;
		const auto& it = map.find(path - sum);
		// path == sum, then path with root as start and current node as the end point will be satisfied;
		if (path - sum == 0)
			++num_results;
		// find all path with current node as end;
		if (it != map.end())
			// ++num_results;
			num_results += it->second;

		++map[path];
		num_results += dfs(curr->left, path, sum, map) + dfs(curr->right, path, sum, map);
		--map[path];

		return num_results;
	}
};

int main() {
	TreeNode node1(10), node2(5), node3(-3), node4(3), node5(2), node6(11), node7(3), node8(-2), node9(1);
	int sum = 8;
	node1.left = &node2; node1.right = &node3;
	node2.left = &node4; node2.right = &node5;
	node3.right = &node6;
	node4.left = &node7; node4.right = &node8;
	node5.right = &node9;
	std::cout << Solution().pathSum(&node1, sum);
	cin.get();
	return 0;
}