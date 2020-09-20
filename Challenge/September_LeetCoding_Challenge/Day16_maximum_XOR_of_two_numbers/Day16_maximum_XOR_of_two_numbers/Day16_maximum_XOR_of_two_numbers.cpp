#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>

using namespace std;


// solution 1:
// check each bit whether to be 1 from the most significant digit;
// xor feature: if a^b = c, then a^c = b, b^c = a.
class Solution1 {
public:
	int findMaximumXOR(vector<int>& nums) {
		int result = 0;
		int mask = 0;
		for (int move_num = 30; move_num >= 0; --move_num) {
			// The mask will grow like  100..000 , 110..000, 111..000,  then 1111...111
			mask = mask | (1 << move_num);
			std::unordered_set<int> all_prefix;
			for (auto & ele : nums) {
				all_prefix.emplace(ele & mask);
			}
			// the possible max number;
			int temp_max = result + (1<<move_num);
			for (auto & ele : all_prefix) {
				// check the prefix of another number whether to exist;
				if (all_prefix.find(temp_max^ele) != all_prefix.end()) {
					result = temp_max;
					break;
				}
			}
		}
		return result;
	}
};

// solutin 2£º
// Trie search;
class Solution {
public:
	class TreeNode {
	public:
		TreeNode* next[2];
		TreeNode() { next[0] = NULL; next[1] = NULL; };
	};
	TreeNode* buildTree(vector<int>& nums) {
		TreeNode* root = new TreeNode(), *cur;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			int num = nums[i];
			cur = root;
			for (int j = 31; j >= 0; j--) {
				int index = ((num >> j) & 1);
				if (cur->next[index] == NULL)
					cur->next[index] = new TreeNode();
				cur = cur->next[index];
			}
		}
		return root;
	}

	int helper(TreeNode* cur, int num) {
		int res = 0;
		for (int i = 31; i >= 0; i--) {
			int index = ((num >> i) & 1) ? 0 : 1;
			if (cur->next[index]) {
				res <<= 1;
				res |= 1;
				cur = cur->next[index];
			}
			else {
				res <<= 1;
				res |= 0;
				cur = cur->next[index ? 0 : 1];
			}
		}
		return res;
	}

	int findMaximumXOR(vector<int>& nums) {
		int res = 0;
		TreeNode* root = buildTree(nums);

		for (auto i : nums) {
			res = max(res, helper(root, i));
		}

		return res;
	}
};

int main() {
	//std::bitset<32> s(1);
	//for (int idx = 0; idx < 32;++idx) {
	//	bool ele = s[idx];
	//	if (ele) {
	//		std::cout << 1;
	//	}
	//	else {
	//		std::cout << 0;
	//	}
	//}

	std::vector<int> nums{ 3, 10, 5, 25, 2, 8 };
	std::cout << Solution().findMaximumXOR(nums);

	std::cout << endl;
	cin.get();
	return 0;
}