#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// solution:
// Divide and Conquer:
// Divide N into N sub problem, whose root value is N and left child, right child are to 
// built respectively.
class Solution {
	std::vector<int> m_value2num;
public:
	int numTrees(int n) {
		m_value2num.emplace_back(1);
		m_value2num.emplace_back(1);
		for (int idx = 2; idx <= n; ++idx) {
			int num = 0;
			for (int root_value = 1; root_value <= idx; ++root_value) {
				// root_value at the root, then num is left sub_tree with root_value-1,
				// right sub_tree with root_value idx-root_value;
				num += m_value2num[root_value - 1] * m_value2num[idx - root_value];
			}
			m_value2num.emplace_back(num);
		}
		return m_value2num[n];
	}
};

int main() {
	std::cout << Solution().numTrees(3);
	cin.get();
	return 0;
}