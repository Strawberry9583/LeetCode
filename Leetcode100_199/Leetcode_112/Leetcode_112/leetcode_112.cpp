
// path sum I:
//Given a binary tree and a sum, determine if the tree has a root - to - leaf path such that adding up all the values along the path equals the given sum.
//
//Note: A leaf is a node with no children.
//
//	Example :
//
//	Given the below binary tree and sum = 22,
//
//	5
//	/ \
//	4   8
//	/   / \
//	11  13  4
//	/ \      \
//	7    2      1


 // Definition for a binary tree node.

#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution1_1 {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr) {
			return false;
		}
		return traversal(root,0, sum);
	}
private:
	bool traversal(const TreeNode* root, int path_sum, int sum) {
		if (root == nullptr) {
			return false;
		}
		if (root->left == nullptr&&root->right==nullptr) {
			path_sum += root->val;
			return path_sum == sum;
		}
		else {
			if (traversal(root->left, path_sum + root->val, sum)) {
				return true;
			}
			else if (traversal(root->right, path_sum + root->val, sum)) {
				return true;
			}
			else {
				return false;
			}
		}
		
	}
};



class Solution1_2 {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr) {
			return false;
		}
		return traversal(root, 0, sum);
	}
private:
	bool traversal(const TreeNode* root, int path_sum, int sum) {
		if (root == nullptr) {
			return false;
		}
		path_sum += root->val;
		if (root->left == nullptr&&root->right == nullptr) {
			
			return path_sum == sum;
		}
		else {
			if (traversal(root->left, path_sum , sum)) {
				return true;
			}
			else if (traversal(root->right, path_sum, sum)) {
				return true;
			}
			else {
				return false;
			}
		}

	}
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


// method: tree traversal (dfs);
class Solution2_1 {
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
		if (root->left == nullptr&& root->right == nullptr&&cur_sum == sum) {
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

// path sum III problem
//You are given a binary tree in which each node contains an integer value.
//
//Find the number of paths that sum to a given value.
//
//The path does not need to start or end at the root or a leaf, but it must go downwards(traveling only from parent nodes to child nodes).
//
//The tree has no more than 1, 000 nodes and the values are in the range - 1, 000, 000 to 1, 000, 000.
//
//Example:
//
//root = [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1], sum = 8
//
//10
/// \
//5 - 3
/// \    \
//3   2   11
/// \   \
//3 - 2   1
//
//Return 3. The paths that sum to 8 are:
//
//1.  5 -> 3
//2.  5 -> 2 -> 1
//3. - 3 -> 11


// method1: traverse all nodes, calc all sum frequency with itself as root; (down-top)
// store the sum frequency with unodered_map;
class Solution3_1 {
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
class Solution3_2 {
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

class Solution3_3 {
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
	TreeNode node1(5), node2(4), node3(8), node4(11), node5(13), node6(4), node7(7), node8(2), node9(1);
	int sum =22;
	node1.left = &node2; node1.right = &node3;
	node2.left = &node4; 
	node3.left = &node5; node3.right = &node6;
	node4.left = &node7; node4.right = &node8;
	node5.right = &node9;
	std::cout << Solution3_3().pathSum(&node1, sum);
	std::cin.get();
	return 0;
}