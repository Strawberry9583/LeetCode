#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
	std::vector<int> result;
public:
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		std::vector<int> vec_1;
		traverse(root1, vec_1);
		std::vector<int> vec_2;
		traverse(root2, vec_2);
		merge(vec_1, vec_2);
		return result;
	}
private:
	void traverse(TreeNode* root, std::vector<int>& vec) {
		if (root == nullptr) {
			return;
		}
		traverse(root->left, vec);
		vec.emplace_back(root->val);
		traverse(root->right, vec);
	}
	
	void merge(std::vector<int>& vec1, std::vector<int> & vec2) {
		result.resize(vec1.size() + vec2.size());
		int idx1 = 0, idx2 = 0;
		int idx = 0;
		while (idx1<vec1.size()&&idx2<vec2.size()) {
			if (vec1[idx1] < vec2[idx2]) {
				result[idx++] = vec1[idx1++];
			}
			else {
				result[idx++] = vec2[idx2++];
			}
		}
		while (idx1<vec1.size()) {
			result[idx++] = vec1[idx1++];
		}
		while (idx2<vec2.size()) {
			result[idx++] = vec2[idx2++];
		}
	}
};

int main() {
	cin.get();
	return 0;
}