#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// method: dfs
// caution: 1. the leading digit can be zero when required number is one-digit;
//          2. the gap may be zero, then only to check the number whose all digits are same;
// Time Complexity: O(N*2^N);
// space complexity: O(2^N);
class Solution {
	std::vector<int> m_result;
	int m_length, m_gap;
public:
	vector<int> numsSameConsecDiff(int N, int K) {
		m_length = N, m_gap = K;
		std::vector<int> digit;
		dfs(digit);
		return m_result;
	}
private:
	void dfs(std::vector<int> & digit) {
		// if the target length==1, then zero can be leading digit;
		if (digit.size() == 0 && m_length == 1) {
			for (int num = 0; num < 10; ++num) {
				digit.emplace_back(num);
				dfs(digit);
				digit.pop_back();
			}
		}
		else if (digit.size() == 0) {
			for (int num = 1; num < 10; ++num) {
				digit.emplace_back(num);
				dfs(digit);
				digit.pop_back();
			}
		}
		else if (digit.size() == m_length) {
			int num = 0;
			for (int power = digit.size() - 1; power >= 0; --power) {
				num += std::pow(10, power)*digit[digit.size() - 1 - power];
			}
			m_result.emplace_back(num);
		}
		else {
			// if gap==0, then digit.back()+m_gap==digit.back()-m_gap, there will be redundant;
			if (m_gap == 0) {
				digit.emplace_back(digit.back());
				dfs(digit);
				digit.pop_back();
			}
			else {
				if (digit.back() + m_gap < 10) {
					digit.emplace_back(digit.back() + m_gap);
					dfs(digit);
					digit.pop_back();
				}
				if (digit.back() - m_gap >= 0) {
					digit.emplace_back(digit.back() - m_gap);
					dfs(digit);
					digit.pop_back();
				}

			}
		}
	}
};

int main() {
	int N = 1, K = 0;
	auto ans = Solution().numsSameConsecDiff(N, K);
	for (auto & ele : ans) {
		std::cout << ele << std::endl;
	}

	cin.get();
	return 0;
}