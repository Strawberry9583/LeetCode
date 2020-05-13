#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<list>
#include<deque>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution1 {
public:
	vector<string> stringMatching(vector<string>& words) {
		std::vector<string> result;
		for (int idx = 0; idx < words.size(); ++idx) {
			if (if_substr(idx, words)) {
				result.emplace_back(words[idx]);
			}
		}
		return result;
	}

	bool if_substr(int idx, const std::vector<string> & words) {

		for (int i = 0; i < words.size(); ++i) {
			//prune for accelerating;
			if (words[i].size()>words[idx].size()&&i != idx&& words[i].find(words[idx])!=string::npos) {
				return true;
			}
		}
		return false;
	}
};


class Solution2 {
public:
	//method 1:
	vector<int> processQueries(vector<int>& queries, int m) {
		vector<int> ans;
		vector<int> p(m);
		for (int i = 0; i < m; i++) {
			p[i] = i + 1;
		}
		for (auto &key : queries) {
			int pos = 0;
			for (int i = 0; i < m; i++) {
				if (p[i] == key) {
					pos = i;
					break;
				}
			}
			ans.push_back(pos);
			p.erase(p.begin() + pos);
			p.insert(p.begin(), key);
		}
		return ans;
	}
	//method 2
	vector<int> processQueries1(vector<int>& queries, int m) {
		std::vector<int> result(queries.size() , 0);
		for (int idx = 0; idx < queries.size(); ++idx) {
			int ele = queries[idx];
			int pre = 0;
			bool pre_exit = false;
			for (pre = idx - 1; pre >= 0; --pre) {
				if (queries[pre] == ele) {
					pre_exit = true;
					break;
				}
			}		
			if (pre_exit) {
				std::unordered_set<int> num_checked;
				for (int cur = pre+1; cur < idx; ++cur) {
					if (num_checked.find(queries[cur])==num_checked.end()) {
						num_checked.emplace(queries[cur]);
					}
				}
				result[idx] = num_checked.size();
			}
			else {
				int larger_num = 0;
				std::unordered_set<int> larger_num_checked;
				for (int cur = 0; cur < idx; ++cur) {
					if (queries[cur] > queries[idx]&&larger_num_checked.find(queries[cur])==larger_num_checked.end()) {
						++larger_num;
						larger_num_checked.emplace(queries[cur]);
					}
				}
				result[idx] = larger_num + ele - 1;
			}
		}
		return result;
	}
};

class Solution4 {
public:
	//the constrains only exists in the linked rows;
	//12 cases, 6 five_cases  can bring 5+4+5+4+5 next states;
	//12 cases, 6 four_cases can bring 5+4+5+4 next states;
	int numOfWays(int n) {
		long int mode = (long int)pow(10, 9) + 7;
		long int case_four=6;
		long int case_five = 6;
		long int result = case_five + case_four;
		for (int i = 1; i < n; ++i) {
			long int temp_four = (case_four*2 + case_five * 2)%mode;
			long int temp_five = (case_four * 2 + case_five * 3)%mode;
			result = (temp_four + temp_five) % mode;
			case_five = temp_five;
			case_four = temp_four;
		}
		return result;
	}
};

int main() {
	Solution4 sol;
	std::cout << sol.numOfWays(7);
	//sol.processQueries(std::vector<int>{3, 1, 2, 1}, 5);
	std::cin.get();
	return 0;
}