#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int diameter = std::numeric_limits<int>::lowest();
		get_depth(root,diameter);
		return diameter;
	}
	int get_depth(TreeNode * root,int& max_diameter) {
		if (root == NULL) {
			if (max_diameter < 0) {
				max_diameter = 0;
			}
			return -1;
		}
		else {
			int left_length = get_depth(root->left,max_diameter) + 1;
			int right_length = get_depth(root->right, max_diameter) + 1;
			int temp_diameter=left_length + right_length;
			if (temp_diameter > max_diameter) {
				max_diameter = temp_diameter;
			}
			return max(left_length, right_length);			
		}
	}
};

int main() {
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5);
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	std::cout << Solution().diameterOfBinaryTree(&n1);
	std::cin.get();
	return 0;
}