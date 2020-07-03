#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {

public:

public:
	int uniquePaths(int m, int n) {
		if (m == 1 && n == 1) {
			return 1;
		}
		m = m + n - 2;
		n = n - 1;
		if (n > m) {
			n = m - 1;
		}
		std::vector<std::vector<int>> c_m_n(m + 1, std::vector<int>(m + 1, -1));
		for (int idx = 0; idx < c_m_n.size(); ++idx) {
			c_m_n[idx][0] = 1;
			c_m_n[idx][1] = idx;
			if (idx < c_m_n.begin()->size()) {
				c_m_n[idx][idx] = 1;
			}
		}
		return get_composition(m, n, c_m_n);
	}
	int get_composition(int m, int n, std::vector<std::vector<int>> & c_m_n) {
		if (c_m_n[m][n] != -1) {
			return c_m_n[m][n];
		}
		else {
			c_m_n[m][n] = get_composition(m - 1, n, c_m_n) + get_composition(m - 1, n - 1, c_m_n);
			return c_m_n[m][n];
		}
	}
};


int main() {
	cin.get();
	return 0;
}