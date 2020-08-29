#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// method: bubble sort similar solution;
// find the max element and move it to the front;
// reverse from the front then the max will be the end;
// find the second max element and move ti to the front 
// ...
// Time complexity: O(N^2); Space complexity: O(N);
class Solution1 {
public:
	vector<int> pancakeSort(vector<int>& A) {
		std::vector<int> result;
		for (int num = 0; num < A.size(); ++num) {
			int idx = 1;
			int cur_max = A[0], cur_max_idx = 0;
			for (; idx < A.size() - num; ++idx) {
				if (cur_max < A[idx]) {
					cur_max = A[idx];
					cur_max_idx = idx;
				}
			}
			if (cur_max_idx == A.size() - num - 1) {
				continue;
			}
			else {
				if (cur_max_idx != 0) {
					result.emplace_back(cur_max_idx + 1);
					std::reverse(A.begin(), A.begin() + cur_max_idx + 1);
				}
				if (A.size() - num - 1 != 0) {
					result.emplace_back(A.size() - num);
					std::reverse(A.begin(), A.begin() + A.size() - num);
				}
			}
		}
		return result;
	}
};

// method2: BST
//Suppose we have sorted A[:i] and now we insert A[i] into the sroted array.
//We have to find how many numbers are smaller than A[i](suppose n values smaller than A[i]).
//If n == 0, the insertion can be done by flip i, flip i + 1. (add to the first)
//If n > 0, the insertion can be done by flip i + 1, flip i + 1 - n, flip i - n, flip i + 1.
//
//Simply add checks to remove flip condition : flip 0.
//The real sub - problem is insertion and count smaller values.So this problem can also be solved using binary search tree.
// Time complexity: O(N*lgN); Space complexity: O(N);
class Node {
public:
	Node *one, *zero;
	int cnt;
};

int push(Node *root, int val) {
	int mask = 1 << 30;
	Node *cur = root;
	int res = 0;
	while (mask) {
		if (val & mask) {
			if (!cur->one)
				cur->one = new Node();
			if (cur->zero)
				res += cur->zero->cnt;
			cur = cur->one;
		}
		else {
			if (!cur->zero)
				cur->zero = new Node();
			cur = cur->zero;
		}
		cur->cnt++;
		mask >>= 1;
	}
	return res;
}

class Solution {
public:
	vector<int> pancakeSort(vector<int>& A) {
		vector<int> res;
		Node *root = new Node();
		for (int i = 0; i < A.size(); i++) {
			int n = push(root, A[i]);
			if (n < i) {
				if (n == 0) {
					if (i > 1) res.push_back(i);
					res.push_back(i + 1);
				}
				else {
					res.push_back(i + 1);
					if (i + 1 - n > 1) res.push_back(i + 1 - n);
					if (i - n > 1) res.push_back(i - n);
					res.push_back(i + 1);
				}
			}
		}
		return res;
	}
};

int main() {
	std::vector<int> test_vec{ 1,2,3};
	Solution().pancakeSort(test_vec);
	for (auto& ele : test_vec) {
		std::cout << ele << " ";
	}
	cin.get();
	return 0;
}