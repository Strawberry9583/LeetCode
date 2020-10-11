#include<iostream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;



 // Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
	void cstr_dfs(TreeNode* root, string & cur_result) {
		if (root == nullptr) {
			cur_result += std::to_string(-1) + " ";
			return;
		}
		else {
			cur_result += std::to_string(root->val) + " ";
			cstr_dfs(root->left, cur_result);
			cstr_dfs(root->right, cur_result);
		}
	}
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string result;
		cstr_dfs(root, result);
		return result;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		stringstream stream(data);
		std::vector<int> all_num;
		int cur_num = 0;
		while (stream >> cur_num) {
			all_num.emplace_back(cur_num);
		}
		TreeNode * root = nullptr;
		int cur_idx = 0;
		dstr_dfs(all_num, cur_idx, root);
		return root;
	}

private:
	void dstr_dfs(const std::vector<int>& all_num, int & cur_idx, TreeNode * & root) {
		if (all_num.size() == cur_idx) {
			return;
		}
		else {
			if (all_num[cur_idx] != -1) {
				root = new TreeNode(all_num[cur_idx++]);
				dstr_dfs(all_num, cur_idx, root->left);
				dstr_dfs(all_num, cur_idx, root->right);
			}
			else {
				root = nullptr;
				++cur_idx;
			}
		}
	}
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
int main() {
	TreeNode node1(2), node2(1), node3(3);
	node1.left = &node2;
	node1.right = &node3;
	Codec* ser = new Codec();
	Codec* deser = new Codec();
	string tree = ser->serialize(&node1);

	TreeNode* ans = deser->deserialize(tree);
	
	cin.get();
	return 0;
}