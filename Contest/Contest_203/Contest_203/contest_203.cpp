#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<functional>
#include<set>
#include<map>

using namespace std;


class Solution1 {
public:
	vector<int> mostVisited(int n, vector<int>& rounds) {
		/*if (rounds.size() == 1) {
			return
		}
*/
		std::vector<int> visit_freq(n + 1, 0);
		for (int round_idx = 0; round_idx + 1 < rounds.size(); ++round_idx) {
			for (int start = rounds[round_idx]; start != rounds[round_idx + 1];) {
				++visit_freq[start];
				++start;
				if (start > n) {
					start = 1;
				}
			}
		}
		++visit_freq[rounds.back()];
		std::vector < std::pair<int, int>> freqAndIdx;
		for (int idx = 1; idx < visit_freq.size(); ++idx) {
			freqAndIdx.emplace_back(visit_freq[idx], idx);
		}
		std::sort(freqAndIdx.begin(), freqAndIdx.end(), [](const std::pair<int, int>& rhs1,
			const std::pair<int, int>& rhs2) {
			return rhs1.first != rhs2.first ? rhs1.first > rhs2.first:rhs1.second < rhs2.second;
		});
		std::vector<int> result;
		result.emplace_back(freqAndIdx.front().second);
		for (int idx = 1; idx < freqAndIdx.size(); ++idx) {
			if (freqAndIdx[idx].first < freqAndIdx[idx - 1].first) {
				break;
			}
			else {
				result.emplace_back(freqAndIdx[idx].second);
			}
		}
		return result;
	}
};

class Solution2 {
public:
	int maxCoins(vector<int>& piles) {
		std::sort(piles.begin(), piles.end(), [](const int rhs1, const int rhs2) {
			return rhs1 > rhs2;
		});
		int num_pick = piles.size() / 3;
		int result = 0;
		for (int idx = 0; idx < num_pick; ++idx) {
			result += piles[2 * idx + 1];
		}
		return result;
	}
};

//class Solution {
//public:
//	int findLatestStep(vector<int>& arr, int m) {
//		if (arr.size() == m) {
//			return m;
//		}
//		std::set<int, int> zero_pos;
//		zero_pos.insert(0); zero_pos.insert((int)arr.size() + 1);
//		int result = -1;
//		for (int step = arr.size(); step > 0; --step) {
//			//auto first_greater = std::upper_bound(zero_pos.begin(), zero_pos.end(), arr[step - 1]);
//			auto first_greater = zero_pos.upper_bound(arr[step - 1]);
//			if (((*first_greater) - arr[step - 1]-1 == m) || (arr[step - 1] - (*(first_greater - 1))-1 == m)) {
//				result=step - 1;
//				break;
//			}
//			else {
//				zero_pos.emplace(first_greater, arr[step - 1]);
//			}
//		}
//		return result;
//	}
//};


class Solution {
public:
	int findLatestStep(vector<int>& arr, int m) {
		if (arr.size() == m) {
			return m;
		}
		std::vector<int> zero_pos{ 0,(int)arr.size() + 1 };

		int result = -1;
		for (int step = arr.size(); step > 0; --step) {
			auto first_greater = std::upper_bound(zero_pos.begin(), zero_pos.end(), arr[step - 1]);
			if (((*first_greater) - arr[step - 1] - 1 == m) || (arr[step - 1] - (*(first_greater - 1)) - 1 == m)) {
				result = step - 1;
				break;
			}
			else {
				zero_pos.emplace(first_greater, arr[step - 1]);
			}
		}
		return result;
	}
};
int main() {
	//std::vector<int>test_vec{ 2,1,2,1,2,1,2,1,2 };
	//int n = 2;
	//auto ans = Solution1().mostVisited(n, test_vec);
	//for (auto ele : ans) {
	//	std::cout << ele << " ";
	//}

	//std::vector<int>test_vec{ 9,8,7,6,5,1,2,3,4 };
	//std::cout << Solution2().maxCoins(test_vec);

	std::vector<int> test_vec{2,1 };
	int m = 2;
	std::cout << Solution().findLatestStep(test_vec, m);

	cin.get();
	return 0;
}