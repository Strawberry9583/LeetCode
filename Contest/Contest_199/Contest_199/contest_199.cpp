#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>


using namespace std;

class Solution1 {
public:
	string restoreString(string s, vector<int>& indices) {
		string result(s.size(), '0');
		for (int idx = 0; idx < indices.size(); ++idx) {
			result[indices[idx]] = s[idx];
		}
		return result;
	}
};

class Solution2 {
public:
	int minFlips(string target) {
		int result = 0;
		for (int idx = 0; idx < target.size(); ++idx) {
			if (target[idx] - '0' == (result % 2)) {
				continue;
			}
			else {
				++result;
			}
		}
		return result;
	}
};



// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution3 {
	int result = 0;
public:
	int countPairs(TreeNode* root, int distance) {
		if (root == nullptr) {
			return result;
		}
		dfs(root,distance,0);
		return result;
	}
	std::vector<int> dfs(TreeNode * node, int distance,int depth) {
		std::vector<int> distance2childnum(distance, 0);
		if (node->left == nullptr&&node->right == nullptr) {
			distance2childnum[0] = 1;
			return distance2childnum;
		}
		std::vector<int> left_data, right_data;
		if (node->left != nullptr) {
			left_data = dfs(node->left, distance, depth + 1);
			for (int idx = left_data.size()-1; idx>0; --idx) {
				left_data[idx] = left_data[idx - 1];
			}
			left_data[0] = 0;
		}
		if (node->right != nullptr) {
			right_data = dfs(node->right, distance, depth + 1);
			for (int idx = right_data.size() - 1; idx>0; --idx) {
				right_data[idx] = right_data[idx - 1];
			}
			right_data[0] = 0;
		}
		for (int left_dis = 0; left_dis<left_data.size()&&left_dis < distance; ++left_dis) {
			for (int right_dis = 0;right_dis<right_data.size()&& right_dis + left_dis <= distance; ++right_dis) {
				result += left_data[left_dis] * right_data[right_dis];
			}
		}
		for (int idx = 0; idx < distance; ++idx) {
			if (idx < left_data.size()) {
				distance2childnum[idx] = left_data[idx];
			}
			if (idx < right_data.size()) {
				distance2childnum[idx] += right_data[idx];
			}
		}
		return distance2childnum;
	}
};




int main() {
	//std::cout<<Solution().minFlips("001011101");
	/*std::vector<int> test_idx{ 4,0,2,6,7,3,1,5 };
	string test_str = "aaiougrt";
	std::cout << Solution().restoreString(test_str, test_idx);*/

	//TreeNode node1(7), node2(1), node3(4), node4(6),node5(5),node6(3),node7(2);
	//node1.left = &node2;
	//node1.right = &node3;
	//node2.left = &node4;
	//node3.left = &node5;
	//node3.right = &node6;
	//node6.right = &node7;

	//int distance = 3;
	//std::cout << Solution3().countPairs(&node1,distance);



	cin.get();
	return 0;
}