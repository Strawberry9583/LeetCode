#include<iostream>
#include<vector>
#include<random>
#include<ctime>
using namespace std;

// normal solution to generate random numbers,
// which is similar to roullete;
class Solution1 {
private:
	std::vector<double> m_ratio;
	std::uniform_real_distribution<double> m_uni_dis;
	mutable std::default_random_engine m_egine;
public:

	Solution(vector<int>& w) {
		m_egine.seed(0);
		double sum = 0.;
		for (auto & ele : w) {
			sum += static_cast<double>(ele);
		}
		m_ratio.reserve(w.size());
		for (auto & ele : w) {
			m_ratio.emplace_back(ele / sum);
		}
		
	}

	int pickIndex() {
		double ratio = m_uni_dis(m_egine);
		int idx = 0;
		for ( ; idx < m_ratio.size(); ++idx) {
			ratio -= m_ratio[idx];
			if (ratio < 0.) {
				break;
			}
		}
		return idx;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(w);
* int param_1 = obj->pickIndex();
*/

// similar to solution1; but with binary search to return idx;
class Solution {
private:
	std::vector<double> m_ratio;
	std::uniform_real_distribution<double> m_uni_dis;
	mutable std::default_random_engine m_egine;
public:

	Solution(vector<int>& w) {
		m_egine.seed(0);
		double sum = 0.;
		for (auto & ele : w) {
			sum += static_cast<double>(ele);
		}
		m_ratio.reserve(w.size());
		for (auto & ele : w) {
			m_ratio.emplace_back(ele / sum);
		}
		for (int idx = 1; idx < w.size(); ++idx) {
			m_ratio[idx] += m_ratio[idx - 1];
		}
	}

	int pickIndex() {
		double ratio = m_uni_dis(m_egine);
		int left = 0, right = m_ratio.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (m_ratio[mid] > ratio) {
				right = mid;
			}
			else if (m_ratio[mid] < ratio) {
				left = mid + 1;
			}
			else if (m_ratio[mid] == ratio) {
				return mid;
			}
		}
		return left == m_ratio.size() ? left - 1 : left;
	}
};

int main() {

	cin.get();
	return 0;
}