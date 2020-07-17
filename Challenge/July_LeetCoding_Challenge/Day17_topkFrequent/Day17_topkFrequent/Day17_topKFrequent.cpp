#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

// similar to linked_hash,
// use hash_map to judge whether the ele existe;
// use vector store the ele;
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		std::unordered_map<int, std::vector<std::pair<int,int>>::iterator> num2ite;
		std::vector<std::pair<int, int>> vec_num_freq; vec_num_freq.reserve(nums.size());
		for (auto & ele : nums) {
			if (num2ite.find(ele) == num2ite.end()) {
				vec_num_freq.emplace_back(ele, 0);
				num2ite[ele] = vec_num_freq.end() - 1;
			}
			else {
				++num2ite[ele]->second;
			}
		}
		std::partial_sort(vec_num_freq.begin(), vec_num_freq.begin() + k, vec_num_freq.end(), []
		(const pair<int, int> & rhs1, const pair<int, int> & rhs2) {return rhs1.second > rhs2.second; });
		std::vector<int> result; result.reserve(k);
		for (int idx = 0; idx < k; ++idx) {
			result.emplace_back(vec_num_freq[idx].first);
		}
		return result;
	}
};

int main() {
	std::vector<int> test_vec{ 1,2,3,1,2,1 };
	int k=1;
	auto ans = Solution().topKFrequent(test_vec, k);
	cin.get();
	return 0;
}