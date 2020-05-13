#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;


class Solution {
public:
	string destCity(vector<vector<string>>& paths) {
		std::unordered_set<string> result;
		for (auto & ele : paths) {
			result.emplace(ele[0]);
		}
		string ans;
		for (auto & ele : paths) {
			if (result.find(ele[1]) == result.end()) {
				ans = ele[1];
				break;
			}
		}
		return ans;
	}
};

int main() {

	std::cin.get();
	return 0;
}