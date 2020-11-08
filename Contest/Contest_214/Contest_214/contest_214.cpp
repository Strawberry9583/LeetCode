#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution2 {
public:
	int minDeletions(string s) {
		std::vector<int> char2freq(26, 0);
		for (auto & ele : s) {
			++char2freq[ele - 'a'];
		}
		std::sort(char2freq.begin(), char2freq.end(), [](int i1, int i2) {return i1 > i2; });
		int result = 0;
		for (int idx = 1; idx < char2freq.size(); ++idx) {
			if (char2freq[idx] == 0) {
				break;
			}
			else {
				if (char2freq[idx]>=char2freq[idx - 1]) {
					int temp = std::max(char2freq[idx - 1] - 1, 0);
					result += char2freq[idx] - temp;
					char2freq[idx] = temp;
				}
			}
		}
		return result;
	}
};

class Solution {
public:
	int maxProfit(vector<int>& inventory, int orders) {
		inventory.emplace_back(0);
		std::sort(inventory.begin(), inventory.end(), [](int i1, int i2) {return i1 > i2; });
		int pre_each_rest = inventory.front();
		int total_gap = 0;
		for (int idx = 0; idx < inventory.size(); ++idx) {
			if (total_gap >= orders) {
				break;
			}
			else {
				if (inventory[idx] == pre_each_rest) {
					continue;
				}
				else if (inventory[idx] < pre_each_rest) {
					int still_need = orders - total_gap;
					if (std::ceil((still_need / pre_each_rest - inventory[idx])) <= idx) {
						int temp = std::ceil(still_need / idx);
						total_gap += (pre_each_rest - temp)*idx;
						pre_each_rest = temp;
					}
					else {
						total_gap += (pre_each_rest - inventory[idx])*idx;
						pre_each_rest = inventory[idx];
					}
				}
			}
		}
		long int result = 0;
		for (int idx = 0; idx < inventory.size(); ++idx) {
			if (orders > inventory[idx] - pre_each_rest + 1) {
				result+=(inventory[idx]+pre_each_rest+1)
			}
		}
	}
};

int main() {
	//string  s= "bbcebab";
	//std::cout << Solution2().minDeletions(s);
	cin.get();
	return 0;
}