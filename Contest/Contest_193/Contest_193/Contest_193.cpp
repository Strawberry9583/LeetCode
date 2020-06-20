#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;


class Solution1 {
public:
	vector<int> runningSum(vector<int>& nums) {
		if (nums.empty()) {
			return vector<int>();
		}
		std::vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		for (int idx = 1; idx < nums.size(); ++idx) {
			dp[idx] = dp[idx - 1] + nums[idx];
		}
		return dp;
	}
};

class Solution2 {
public:
	int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
		std::unordered_map<int, int> num2fre;
		for (auto & ele : arr) {
			++num2fre[ele];
		}
		std::vector<std::pair<int, int>> num2freVec; num2freVec.reserve(num2fre.size());
		for (auto & ele : num2fre) {
			num2freVec.emplace_back(ele.first, ele.second);
		}
		std::sort(num2freVec.begin(), num2freVec.end(), [](const pair<int, int> & rhs1, const pair<int, int> & rhs2)
		{return rhs1.second < rhs2.second; });
		int idx = 0;
		while (k>=0&& idx<num2freVec.size()) {
			int temp_k = k;
			k -= num2freVec[idx].second;
			if (temp_k < num2freVec[idx].second) {
				num2freVec[idx].second -= temp_k;
			}
			else {
				num2freVec[idx].second = 0;
			}
			++idx;

		}
		if (k > 0) {
			return 0;
		}
		else {
			if(idx-1<0){
				
			}
			return num2freVec[idx - 1].second == 0 ? num2freVec.size() - idx : num2freVec.size() - idx + 1;
		}
	}
};

// min-max problem: intuition to use binary search;
// firstly, set a num to check the validation;
// according to the check result to shorten the range to a half, 
// until get the minimum valid result;
class Solution3 {
public:
	int minDays(vector<int>& bloomDay, int m, int k) {
		if (bloomDay.size() < m*k) {
			return -1;
		}
		int left = 0, right = 1+1e9;
		while (left<right) {
			int mid = left + (right - left) / 2;
			bool flag=check_validation(bloomDay, m, k, mid);
			if (flag) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		if (left == 1+1e9) {
			return -1;
		}
		else {
			return left;
		}
	}
	// check current day whether is ennough to make;
	bool check_validation(std::vector<int>& bloom, int m, int k, int day) {
		int sequence = 0;
		for (int idx = 0; idx < bloom.size(); ++idx) {
			if (bloom[idx] <= day) {
				++sequence;
				if (sequence >= k) {
					sequence -= k;
					--m;
					if (m == 0) {
						return true;
					}
				}
			}
			else {
				sequence = 0;
			}
		}
		return false;
	}
};

// solution1: every time find its parent, getting TLE finally.
class TreeAncestor1 {
private:
	std::vector<int> m_parent;
public:
	TreeAncestor1(int n, vector<int>& parent):m_parent(parent) {

	}

	int getKthAncestor(int node, int k) {
		while (k>0) {
			if (node == 0) {
				return -1;
			}
			else {
				node = m_parent[node];
				--k;
			}
		}
		return node;
	}
};

// soltution2: binary jump method;
// construct the tree not only the first step parent, but record also 2, 4, 8... step parent.
// meanwhile, for k_th parent, resolve the K into 2' power numbers.
// then every step just look up its 2's power parents until there is no parent.
class TreeAncestor{
private:
	vector<vector<int>> m_parent;
public:
	TreeAncestor(int n, vector<int>& parent) {
		// at most 2^20 step parent;
		m_parent.resize(n, vector<int>(20));
		for (int i = 0; i < n; i++) m_parent[i][0] = parent[i];
		for (int j = 1; j < 20; j++) {
			for (int i = 0; i < n; i++) {
				if (m_parent[i][j - 1] == -1) m_parent[i][j] = -1;
				else m_parent[i][j] = m_parent[m_parent[i][j - 1]][j - 1];
			}
		}
	}
	int getKthAncestor(int node, int k) {
		for (int i = 0; i < 20; i++) {
			// get the 2^i power number;
			if ((k >> i) & 1) {
				node = m_parent[node][i];
				if (node == -1) return -1;
			}
		}
		return node;
	}
};

int main() {
	//Solution2 sol;
	//std::vector<int>test_vec{ 1 };
	//int k = 0;
	//std::cout << sol.findLeastNumOfUniqueInts(test_vec, k);

	std::vector<int> test_vec{ 1,10,3,10,2 };
	int m = 3;
	int k = 1;
	std::cout << Solution3().minDays(test_vec, m, k);

	//std::vector<int> test_vec{ -1, 0, 0, 1, 1, 2, 2 };
	//int node_num = 7;
	//TreeAncestor tr(node_num, test_vec);
	//std::cout << tr.getKthAncestor(3, 1);
	//std::cout << tr.getKthAncestor(5, 2);
	//std::cout << tr.getKthAncestor(6, 3);
	cin.get();
	return 0;
}