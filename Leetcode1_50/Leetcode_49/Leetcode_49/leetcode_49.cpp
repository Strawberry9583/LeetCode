#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<array>
using namespace std;

class Solution1 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		std::vector<std::vector<string>> result;
		//use string as key to record the occurance of every char;
		//use int as value to record the group idx with corresponding key;
		std::map<string, int> charnum2idx;
		for (const auto & _ele : strs) {
			string s(26, 0);
			for (const auto & _chara : _ele) {
				++s[_chara - 'a'];
			}
			auto found_idx = charnum2idx.find(s);
			if (found_idx == charnum2idx.end()) {
				charnum2idx.emplace(s, result.size());
				result.emplace_back();
				result.rbegin()->emplace_back(_ele);
			}
			else {
				result[found_idx->second].emplace_back(_ele);
			}
		}
		return result;
	}
};


class Solution2 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		//use hash map to record the sorted string as key;
		std::unordered_map<string, std::vector<string>> res;
		for (auto& ele : strs) {
			auto temp_str = ele;
			std::sort(ele.begin(), ele.end());
			res[ele].emplace_back(std::move(temp_str));
		}
		std::vector<std::vector<string>> ans;
		for (auto & group : res) {
			ans.emplace_back(std::move(group.second));
		}
		return ans;
	}
};


class Solution {
public:

	array<char, 26> getKey(const string& str) {
		array<char, 26> arr{};
		for (const auto& ch : str)
			arr[ch - 'a']++;
		return arr;
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<array<char, 26>, vector<string>> m;
		for (auto&& str : strs)
			m[getKey(str)].push_back(move(str));

		vector<vector<string>> v;
		//transform the map into the vector;
		transform(begin(m), end(m), back_inserter(v), [](auto&& p) { return get<vector<string>>(move(p)); });
		return v;
	}
};


int main() {

	Solution sol;
	std::vector<string> test{ "eat", "tea", "tan", "ate", "nat", "bat" };
	auto ans = sol.groupAnagrams(test);
	for (const auto & ele : ans) {
		for (const auto & _ele : ele) {
			std::cout << _ele << "  ";
		}
		std::cout << std::endl;
	}


	std::cin.get();
	return 0;
}