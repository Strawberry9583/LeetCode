#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<bitset>

using namespace std;

// TLE: simulation
class Solution1 {
public:
	vector<int> prisonAfterNDays(vector<int>& cells, int N) {
		if (N<1) { return cells; }
		std::vector<int> temp(cells.size(), 0);
		for (int idx = 1; idx<cells.size() - 1; ++idx) {
			temp[idx] = (cells[idx - 1] == cells[idx + 1]);
		}
		*cells.begin() = 0;
		*cells.rbegin() = 0;
		cells = temp;
		--N;
		while (N>0) {
			for (int idx = 1; idx<cells.size() - 1; ++idx) {
				temp[idx] = (cells[idx - 1] == cells[idx + 1]);
			}
			cells = temp;
			--N;
		}
		return cells;
	}
};

// solution2:
// record the history sequence then generate the next sequence;
class Solution {
public:
	vector<int> prisonAfterNDays(vector<int>& cells, int N) {
		std::bitset<8> bits(0);
		for (int idx = 0; idx < 8; ++idx) {
			if (cells[idx]) {
				bits[idx] = 1;
			}
		}
		std::vector<bitset<8>> record;
		while (N>0) {
			--N;
			std::bitset<8> left = bits << 1;
			std::bitset<8> right = bits >> 1;
			bits = ~(left^right);
			bits[0] = 0;
			bits[7] = 0;
			auto ele = std::find(record.begin(), record.end(), bits);
			if ( ele!= record.end()) {
				bits = *(ele + (N%record.size()));
				break;
			}
			else {
				record.emplace_back(bits);
			}
		}
		std::vector<int> result(8,0);
		for (int idx = 0; idx < 8; ++idx) {
			if(bits[idx]) {
				result[idx] = 1;
			}
		}
		return result;
	}
};
int main() {
	std::vector<int> test_vec = { 0,1,0,1,1,0,0,1 };
	int N = 7;
	auto ans = Solution().prisonAfterNDays(test_vec, N);
	
	cin.get();
	return 0;
}