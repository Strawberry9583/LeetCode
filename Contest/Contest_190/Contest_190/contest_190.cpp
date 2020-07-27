#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<functional>
#include<string>

using namespace std;

// Check If a Word Occurs As a Prefix of Any Word in a Sentence
class Solution1 {
public:
	int isPrefixOfWord(string sentence, string searchWord) {
		std::vector<string> all_words;
		int idx_pre=0;
		int idx_cur = 0;
		for (int idx_cur = 0; idx_cur < sentence.size(); ++idx_cur) {
			if (sentence[idx_cur] ==' ') {
				all_words.emplace_back(sentence.substr(idx_pre, idx_cur - idx_pre));
				idx_pre = idx_cur+1;
			}
		}
		all_words.emplace_back(sentence.substr(idx_pre, idx_cur - idx_pre));
		for (int idx = 0; idx < all_words.size(); ++idx) {
			if (all_words[idx].find(searchWord) == 0) {
				return idx+1;
			}
		}
		return -1;
	}
};


// Maximum Number of Vowels in a Substring of Given Length
class Solution2 {
public:
	bool is_vowel(char c) {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}

	int maxVowels(string s, int k) {
		int result = 0;
		int cur_vowel_num = 0;
		for (int cur_idx = 0; cur_idx < s.size(); ++cur_idx) {
			if (is_vowel(s[cur_idx])) {
				++cur_vowel_num;
			}
			if (cur_idx >= k&&is_vowel(s[cur_idx - k])) {
				--cur_vowel_num;
			}
			if (cur_vowel_num > result) {
				result = cur_vowel_num;
			}
		}
		return result;
	}
};


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
	TreeNode * right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode*left, TreeNode*right) :val(x), left(left), right(right) {}
};


// Pseudo - Palindromic Paths in a Binary Tree
class Solution3 {
	int m_path_num=0;
public:
	int pseudoPalindromicPaths(TreeNode* root) {
		if (root == nullptr) {
			return m_path_num;
		}
		else {
			std::vector<int> num2freq(10, 0);
			traverse(root, num2freq);
			return m_path_num;
		}
	}
	void traverse(TreeNode * root, std::vector<int>& num2freq) {
		if (root->left==nullptr&&root->right==nullptr) {
			++num2freq[root->val];
			if (is_palindromic(num2freq)) {
				++m_path_num;
			}
			--num2freq[root->val];
			return;
		}
		++num2freq[root->val];
		if (root->left) {
			traverse(root->left, num2freq);
		}
		if (root->right) {
			traverse(root->right, num2freq);
		}
		--num2freq[root->val];
	}
	bool is_palindromic(std::vector<int>& num2freq) {
		int odd_num = 0;
		for (auto & ele : num2freq) {
			if (ele & 1) {
				++odd_num;
				if (odd_num > 1) {
					return false;
				}
			}
		}
		return true;
	}
};

// Max Dot Product of Two Subsequences
class Solution4 {
public:
	int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
		std::vector<std::vector<int>> dp(nums1.size(), std::vector<int>(nums2.size(),-1001));
		dp[0][0] = nums1[0] * nums2[0];
		for (int idx1 = 0; idx1 < nums1.size(); ++idx1) {
			for (int idx2 = 0; idx2 < nums2.size(); ++idx2) {
				if (idx1 == 0) {
					if (idx2 != 0) {
						dp[idx1][idx2] = max(dp[idx1][idx2 - 1], nums1[0] * nums2[idx2]);

					}
				}
				else if (idx2 == 0) {
					dp[idx1][idx2] = max(dp[idx1 - 1][idx2], nums1[idx1] * nums2[0]);
				}
				else {
					dp[idx1][idx2] = max({ dp[idx1][idx2 - 1],dp[idx1 - 1][idx2],
						dp[idx1 - 1][idx2 - 1] + nums1[idx1] * nums2[idx2],nums1[idx1] * nums2[idx2]
					});
				}
			}
		}
		return dp[nums1.size() - 1][nums2.size() - 1];
	}
};

int main() {
	//problem1:
	//string sentence = "i love burger", searchWord = "burg";
	//std::cout << sol.isPrefixOfWord(sentence, searchWord);
	//problem3:
	//TreeNode node1(2), node2(3), node3(1), node4(3), node5(1), node6(1);
	//node1.left = &node2;
	//node1.right = &node3;
	//node2.left = &node4;
	//node2.right = &node5;
	//node3.right = &node6;
	//std::cout << sol.pseudoPalindromicPaths(&node1);

	//proble2:
	//string test = "weallloveyou";
	//int k = 7;
	//std::cout << sol.maxVowels(test, k);
	Solution4 sol;
	std::vector<int> nums1{ 2,1,-2,5 }, nums2{ 3,0,-6 };
	std::cout << sol.maxDotProduct(nums1, nums2);
	cin.get();
	return 0;
}