#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>

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
 
class Solution {
public:
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		std::map<int, std::vector<std::pair<int,int>>> x2yandvalue;
		traversal(root, x2yandvalue,0,0);
		std::vector<std::vector<int>> result(x2yandvalue.size());
		int row_idx = 0;
		for (auto & row : x2yandvalue) {
			std::vector<std::pair<int, int>> temp(row.second.begin(), row.second.end());
			std::sort(temp.begin(), temp.end(), [](const std::pair<int, int> &rhs1, const std::pair<int, int>& rhs2) {
				return rhs1.first == rhs2.first ? rhs1.second < rhs2.second : rhs1.first > rhs2.first;
			});
			result[row_idx].resize(temp.size());
			for (int idx = 0; idx < temp.size(); ++idx) {
				result[row_idx][idx] = temp[idx].second;
			}
			++row_idx;
		}
		return result;
	}
private:
	void traversal(const TreeNode * root, std::map < int, std::vector<std::pair<int, int>>>& x2yandvalue,int cur_x,int cur_y) {
		if (root == nullptr) {
			return;
		}
		
		x2yandvalue[cur_x].emplace_back(cur_y, root->val);

		traversal(root->left, x2yandvalue, cur_x - 1, cur_y - 1);
		traversal(root->right, x2yandvalue, cur_x + 1, cur_y - 1);
	}
};

int main() {
	TreeNode node1(3), node2(9), node3(20), node4(15), node5(7);
	node1.left = &node2;
	node1.right = &node3;
	node3.left = &node4;
	node3.right = &node5;
	auto ans = Solution().verticalTraversal(&node1);
	cin.get();
	return 0;
}