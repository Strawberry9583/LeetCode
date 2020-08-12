#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex == 0) {
			return std::vector<int>(1, 1);
		}
		std::vector<int> pre(1, 1);
		std::vector<int> cur(pre.size() + 1, 1);
		while (cur.size() != rowIndex + 1) {
			auto temp = cur;
			pre = cur;
			cur.resize(cur.size() + 1, 1);
			int left = 1, right = cur.size() - 2;
			while (left <= right) {
				cur[left] = cur[right] = pre[left] + pre[left - 1];
				++left; --right;
			}
			//pre = temp;

		}
		return cur;
	}
};


int main() {
	auto  result = Solution().getRow(5);
	for (auto & ele : result) {
		std::cout << ele << " " << std::endl;
	}
	cin.get();
	return 0;
}