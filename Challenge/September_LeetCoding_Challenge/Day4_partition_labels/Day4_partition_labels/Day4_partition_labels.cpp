#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> partitionLabels(string S) {
		std::vector<int> result;
		std::vector<pair<int, int>> char2range(26, { -1,-1 });
		for (int idx = 0; idx < S.size(); ++idx) {
			if (char2range[S[idx] - 'a'].first == -1) {
				char2range[S[idx] - 'a'].first = idx;
				char2range[S[idx] - 'a'].second = idx;
			}
			else {
				char2range[S[idx] - 'a'].second = idx;
			}
		}
		int right_bound = 0;
		int left_bound = 0;
		for (int idx = 0; idx < S.size(); ++idx) {
			if (right_bound < char2range[S[idx] - 'a'].second) {
				right_bound = char2range[S[idx] - 'a'].second;
			}
			if (idx == right_bound) {
				result.emplace_back(right_bound - left_bound + 1);
				left_bound = right_bound + 1;
			}
		}
		return result;
	}
};

int main() {
	string s = "ababcbacadefegdehijhklij";
	auto ans=Solution().partitionLabels(s);
	cin.get();
	return 0;
}