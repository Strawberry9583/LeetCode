#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int numJewelsInStones(string J, string S) {
		std::unordered_set<char> jewel_set;
		for (auto && ele : J) {
			jewel_set.emplace(ele);
		}
		int result = 0;
		for (auto & ele : S) {
			if (jewel_set.find(ele) != jewel_set.end()) {
				++result;
			}
		}
		return result;
	}
};
int main() {
	std::vector<int> test_vec;
	int test_cap = test_vec.capacity();
	for(int i=0;i<10000;++i){
		if (test_vec.capacity() != test_cap) {
			std::cout << test_cap << std::endl;
			test_cap = test_vec.capacity();
		}
		test_vec.emplace_back(std::move(i));
		
	}

	std::cin.get();
	return 0;
}