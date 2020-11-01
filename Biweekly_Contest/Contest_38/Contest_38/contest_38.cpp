#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<unordered_map>

using namespace std;


class Solution {
public:
	vector<int> frequencySort(vector<int>& nums) {
		std::unordered_map<int, int> num2freq;
		for (const auto & ele : nums) {
			++num2freq[ele];
		}
		std::sort(nums.begin(), nums.end(), [& num2freq](const int n1,const  int n2) {return num2freq[n1] == num2freq[n2] ? n1 > n2:num2freq[n1] < num2freq[n2]; });
		return nums;
	}
};

class Solution2 {
public:
	int maxWidthOfVerticalArea(vector<vector<int>>& points) {
		std::sort(points.begin(), points.end(), [](const vector<int> & p1, const vector<int>& p2) {
			return p1.front() < p2.front();
		});
		int result = 0;
		for (int idx = 1; idx < points.size(); ++idx) {
			if (points[idx].front() - points[idx - 1].front() > result) {
				result = points[idx].front() - points[idx - 1].front();
			}
		}
		return result;
	}
};

class Solution3 {
public:
	int countSubstrings(string s, string t) {
		std::vector<std::vector<int>> samesub_num(s.size()+1, std::vector<int>(t.size()+1, 0));
		for (int s_idx = 1; s_idx <= s.size(); ++s_idx) {
			for (int t_idx = 1; t_idx <= t.size(); ++t_idx) {
				if (s[s_idx-1] == t[t_idx-1]) {
					samesub_num[s_idx][t_idx] = samesub_num[s_idx - 1][t_idx - 1] + 1;
				}
				else {
					samesub_num[s_idx][t_idx] = 0;
				}
			}
		}
		int result = 0;
		std::vector<std::vector<int>> dp(s.size()+1, std::vector<int>(t.size()+1, 0));
		for (int s_idx = 1; s_idx <= s.size(); ++s_idx) {
			for (int t_idx = 1; t_idx <= t.size(); ++t_idx) {
				if (s[s_idx-1] == t[t_idx-1]) {
					dp[s_idx][t_idx] = dp[s_idx-1][t_idx - 1];
				}
				else {
					dp[s_idx][t_idx]= samesub_num[s_idx-1][t_idx-1] + 1;
				}
				result += dp[s_idx][t_idx];
			}
		}
		return result;
	}
};

int main() {
	std::vector<int> nums{ -1,1,-6,4,5,-6,1,4,1 };
	auto ans = Solution().frequencySort(nums);
	for (auto & ele : ans) {
		std::cout << ele << " ";
	}

	//std::vector<std::vector<int>> test_vec{{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}};
	//std::cout << Solution2().maxWidthOfVerticalArea(test_vec);

	//string  s = "aba", t = "baba";
	//std::cout << Solution3().countSubstrings(s, t);


	cin.get();
	return 0;
}