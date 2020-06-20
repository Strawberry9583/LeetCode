#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<functional>
#include<algorithm>
#include<list>
#include<unordered_set>
#include<set>
#include<bitset>
using namespace std;

class Solution1 {
public:
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		int result = 0;
		for (int idx = 0; idx < startTime.size(); ++idx) {
			if (startTime[idx] >= queryTime&& endTime[idx] <= queryTime) {
				++result;
			}
		}
		return result;
	}
};

//sort the string with length the original idx;
class Solution2 {
public:
	string arrangeWords(string text) {
		std::vector<std::pair<string,int>> res_ve;
		auto space_pre = 0;
		auto space_cur = text.find_first_of(' ', space_pre);
		while (space_cur!=string::npos) {
			res_ve.emplace_back(text.substr(space_pre, space_cur - space_pre),space_pre);
			space_pre = space_cur+1;
			space_cur = text.find_first_of(' ', space_pre);
		}
		res_ve.emplace_back(text.substr(space_pre), space_pre);
		res_ve[0].first[0] = tolower(res_ve[0].first[0]);
		auto compare= [](const pair<string, int> & rhs1, const pair<string, int> & rhs2)->bool {
			return rhs1.first.size() == rhs2.first.size() ? rhs1.second < rhs2.second : rhs1.first.size() < rhs2.first.size();
		};
		std::sort(res_ve.begin(), res_ve.end(),compare);
		string result;
		for (auto & ele : res_ve) {
			result += ele.first + " ";
		}
		result[0] = toupper(result[0]);
		result.erase(result.end()-1);
		return result;
	}
};

// Check all pair whether there are includsion:
// Person number: m; Company number: n; Company length: h;
// Time Complexity O(m*n*m), Space Complexity: O(m*n*h)
class Solution3_1 {
public:
	vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
		if (favoriteCompanies.empty()) {
			return std::vector<int>();
		}
		std::vector<std::pair<int, unordered_set<string>>> idx_and_set;
		for (int idx = 0; idx < favoriteCompanies.size(); ++idx) {
			idx_and_set.emplace_back(idx, unordered_set<string>(favoriteCompanies[idx].begin(), favoriteCompanies[idx].end()));
		}
		std::vector<int> result;
		for (int idx = 0; idx < idx_and_set.size(); ++idx) {
			//bool if_include = false;
			for (int cur = 0; cur < idx_and_set.size(); ++cur) {
				if (cur != idx&& if_included(idx_and_set[idx].second, idx_and_set[cur].second)) {
					idx_and_set[idx].first = -1;
					break;
				}
			}
			if (idx_and_set[idx].first != -1) {
				result.emplace_back(idx);
			}
		}
		return result;
	}
	//whether rsh1 was included by rhs2;
	bool if_included(std::unordered_set<string> & rhs1, std::unordered_set<string> & rhs2) {
		int count = 0;
		for (auto & ele : rhs1) {
			//prune for exlusion;
			if (rhs2.find(ele) == rhs2.end()) {
				return false;
			}
		}
		return true;
	}
};

// Simialar to solution3_2, 
// but sort for every person to use the include algorithm offered by STL;
// For include algorithm:
// Returns true if the sorted range [first2, last2) is a subsequence of the sorted range [first1, last1).
// Person number: m; Company number: n; Company length: h;
// Time Complexity O(m*n*h), Space Complexity: O(m*n*h)
class Solution3_2 {
public:
	vector<int> peopleIndexes(vector<vector<string>>& favs) {
		for (auto &comps : favs)
			sort(begin(comps), end(comps));
		vector<int> res;
		for (auto i = 0; i < favs.size(); ++i) {
			bool notSubset = true;
			for (auto j = 0; j < favs.size() && notSubset; ++j) {
				if (i == j)
					continue;
				notSubset = !includes(begin(favs[j]), end(favs[j]), begin(favs[i]), end(favs[i]));
			}
			if (notSubset)
				res.push_back(i);
		}
		return res;
	}
};

//solution 3_3;
//use bitset to record whether existis of a campany for specific person;
//Actually the biset is used as a hashcode for to represent the companies the person have;
// Person number: m; Company number: n; Company length: h;
// Time Complexity O(m*n), Space Complexity: O(m*n)
class Solution {
public:
	vector<int> peopleIndexes(vector<vector<string>>& favs) {
		std::unordered_map<string, int> campany2idx;
		for (auto & person : favs) {
			for (auto & com : person) {
				if (campany2idx.find(com) == campany2idx.end()) {
					campany2idx[com] = campany2idx.size();
				}
			}
		}
		//because the max number of company is 500*100;
		//then the idx of company is in [1,500000] so size should be 500001;
		//though the testcase is not sufficient, max number of company should be considerred.
		std::vector<std::bitset<500001>> per_and_company;
		for (auto & per : favs) {
			std::bitset<500001> company;
			for (auto & com : per) {
				company[campany2idx[com]] = 1;
			}
			per_and_company.emplace_back(std::move(company));
		}
		std::vector<int> result;
		for (int i = 0; i < favs.size(); ++i) {
			bool is_include = false;
			for (int j = 0; j < favs.size(); ++j) {
				if(i==j){
					continue;
				}
				else {
					//the person[i] is included by person[j];
					if (per_and_company[i] == (per_and_company[i] & per_and_company[j])) {
						is_include = true;
						break;
					}
				}
			}
			if (!is_include) {
				result.emplace_back(i);
			}
		}
		return result;
	}
};

int main() {
	//Solution2 sol;
	//string test = "To be or not to be";
	//std::cout<<sol.arrangeWords(test);

	Solution sol;
	std::vector<std::vector<string>> test = { {"leetcode", "google", "facebook"}, {"google", "microsoft"}, {"google", "facebook"}, {"google"}, {"amazon"} };
	auto ans = sol.peopleIndexes(test);
	for (auto & idx : ans) {
		std::cout << idx << " ";
	}



	cin.get();
	return 0;
}