#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>


using namespace std;


/*class Solution {
public:
	bool comapare(string & s1, string & s2) {
		stringstream ss;
		ss << s1;
		vector<string> vec_s1, vec_s2;
		while (1) {
			string temp_str;
			if (ss >> temp_str){
				vec_s1.push_back(temp_str);
			}
			else {
				break;
			}
		}
		ss << s2;
		while (1) {
			string temp_str;
			if (ss >> temp_str) {
				vec_s2.push_back(temp_str);
			}
			else {
				break;
			}
		}
		for (size_t s1_i = 1, s2_i = 1; s1_i < vec_s1.size() && s2_i < vec_s2.size();) {
			if(vec_s1[s1_i][0]>='0'&&vec_s1[s1_i][0]<='9')
		}
		
	}
	vector<string> reorderLogFiles(vector<string>& logs) {

	}
};*/


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		int sum = 0;
		 tree_sum(sum,root, L, R);
		 return sum;
	}
	void tree_sum(int & sum, TreeNode* root, int & l, int & r) {
		if (root!= NULL) {
			if (root->val > r) {
				tree_sum(sum, root->left, l, r);
			}
			else if(root->val < l) {
				tree_sum(sum, root->right, l, r);
			}
			else {
				tree_sum(sum, root->left, l, r);
				tree_sum(sum, root->right, l, r);
				if (root->val >= l&&root->val <= r) {
					sum += root->val;
				}
			}

		}
		else {
			return;
		}

	}
};


int main() {

	Solution sol;
	TreeNode node1(10), node2(5), node3(15), node4(3), node5(7), node6(18);
	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	node3.right = &node6;

	auto ans=sol.rangeSumBST(&node1, 7, 15);
	cout << ans;
	cin.get();
	return 0;
}