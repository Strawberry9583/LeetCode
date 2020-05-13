#include<vector>
#include<iostream>
#include<set>
#include<functional>
#include<algorithm>
#include<xtree>
#include<memory>
using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) :val(x), left(left), right(right) {}
};
class Solution {
private:
	int depth_x = -1, depth_y = -1;
	TreeNode * root_x = nullptr, *root_y = nullptr;
public:
	bool isCousins(TreeNode* root, int x, int y) {
		int depth = 0;
		TreeNode* ele_root = nullptr;
		find_depth_and_root(root,x,y,depth,ele_root);
		if (depth_x == depth_y&&root_x != root_y) {
			return true;
		}
		else {
			return false;
		}
	}
	void find_depth_and_root(TreeNode * root, int find_ele_x,int find_ele_y, int depth, TreeNode* ele_root) {
		if (depth_x != -1 && depth_y != -1) {
			return;
		}
		else {
			if (root == nullptr) {
				return;
			}
			else if (root->val == find_ele_x) {
				depth_x = depth;
				root_x = ele_root;
			}
			else if (root->val == find_ele_y) {
				depth_y = depth;
				root_y = ele_root;
			}
			else {
				find_depth_and_root(root->left, find_ele_x,find_ele_y, depth + 1, root);
				find_depth_and_root(root->right, find_ele_x,find_ele_y, depth + 1, root);
			}
		}
	}
};

int main() {
	//std::shared_ptr<_Tree<_Tset_traits<int, std::less<int>, std::allocator<int>, false>>> test(std::make_shared<_Tree<_Tset_traits<int, std::less<int>, std::allocator<int>, false>> >(new std::less<int>()));
	//std::_Tree<_Tset_traits<int, std::less<int>, std::allocator<int>, false>> test(less<int>());
	//test.insert(1);
	//_Tree<_Tset_traits<int, std::less<int>, std::allocator<int>, false>>(less<int>()).insert(1);
	//rb_tree.insert(1);
	//rb_tree
	//rb_tree.insert(1);
	//rb_tree.insert(2);
	//std::cout << rb_tree.count(1);
	//std::cout << rb_tree.size();
	//std::cout << rb_tree.max_size();
	std::multiset<int> se;
	std::set<int> s;
	TreeNode node1(1), node2(2), node3(3), node4(4), node5(5);
	node1.left = &node2;
	node1.right = &node3;
	node2.right = &node4;
	node3.right = &node5;
	Solution sol;
	std::cout << sol.isCousins(&node1, 4, 5);
	std::cin.get();
	return 0;
}