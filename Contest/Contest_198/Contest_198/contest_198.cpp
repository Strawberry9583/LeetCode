#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_set>
#include<string>

using namespace std;

//problem 1
class Solution1 {
public:
	int numWaterBottles(int numBottles, int numExchange) {
		int result = 0;
		int full = numBottles, empty = 0;
		while (full+empty>=numExchange) {
			result += full;
			int temp = empty;
			empty = (full + empty) % numExchange;
			full = (temp + full) / numExchange;
		}
		return result+full;
	}
};

// problem 2:
// solution2_1: TLE
// construct the direct graph; O(n^2);
// DFS: O(n*26)=O(n);
class Solution2_1 {
	std::vector<std::vector<int>> m_graph;
	std::vector<std::vector<int>> m_result;
public:
	vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
		//convert to list to speed up following erase operation;
		std::list<std::vector<int>> all_edges;
		for (auto & ele : edges) {
			all_edges.emplace_back(std::move(ele));
		}
		m_graph.resize(n, vector<int>());
		// construct the direct graph; O(n^2);
		std::vector<int> flag(n, 0);
		std::queue<int> que_to_find_child; que_to_find_child.emplace(0);
		while (!que_to_find_child.empty()) {
			int find_child = que_to_find_child.front();
			que_to_find_child.pop();
			for (auto edge = all_edges.begin(); edge != all_edges.end(); ) {
				if ((*edge)[0] == find_child) {
					m_graph[find_child].emplace_back((*edge)[1]);
					que_to_find_child.emplace((*edge)[1]);
					edge=all_edges.erase(edge);
				}
				else if ((*edge)[1] == find_child) {
					m_graph[find_child].emplace_back((*edge)[0]);
					que_to_find_child.emplace((*edge)[0]);
					edge = all_edges.erase(edge);
				}
				else {
					++edge;
				}
			}
		}
		std::unordered_set<char> to_find;
		m_result.resize(n, std::vector<int>(26,0));
		dfs(0,labels,to_find);
		std::vector<int> ans(n, 0);
		for (int idx = 0; idx < n; ++idx) {
			ans[idx] = m_result[idx][labels[idx] - 'a'];
		}
		return ans;
	}
	void dfs(int cur_idx,const string & labels, std::unordered_set<char>  to_find) {
		std::unordered_set<char> next_find(to_find);
		next_find.emplace(labels[cur_idx]);
		for (auto & next : m_graph[cur_idx]) {
			dfs(next, labels,next_find);
			for (auto & to_update:next_find) {
				m_result[cur_idx][to_update-'a'] += m_result[next][to_update-'a'];
			}
		}
		++m_result[cur_idx][labels[cur_idx] - 'a'];
	}
};

// solution2_2: similar to solution2_1;
// before search, judge their relation to avoid construct an directed graph;
// construct undirect graph; O(n);
// DFS; O(n*26)=O(n);
class Solution2_2 {
	std::vector<std::vector<int>> m_graph;
	std::vector<std::vector<int>> m_result;
public:
	vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
		m_graph.resize(n, vector<int>());
		for (auto & ele : edges) {
			m_graph[ele[0]].emplace_back(ele[1]);
			m_graph[ele[1]].emplace_back(ele[0]);
		}
		m_result.resize(n, std::vector<int>(26, 0));
		std::vector<int> visited(n, 0);
		dfs(0, labels, visited);
		std::vector<int> ans(n, 0);
		for (int idx = 0; idx < n; ++idx) {
			ans[idx] = m_result[idx][labels[idx] - 'a'];
		}
		return ans;
	}
	void dfs(int cur_idx, const string & labels,std::vector<int> & visited) {
		visited[cur_idx] = 1;
		for (auto & next : m_graph[cur_idx]) {
			//skip the father node owing to the bi-direct graph;
			if (visited[next]==1) {
				continue;
			}
			else {
				//calc the child inforamtion
				dfs(next, labels,visited);
				for (int idx = 0; idx < 26; ++idx) {
					// gather the num for all char cases;
					m_result[cur_idx][idx] += m_result[next][idx];
				}
			}
		}
		//restore the status;
		visited[cur_idx] = 0;
		//gather infor of current node
		++m_result[cur_idx][labels[cur_idx] - 'a'];
	}
};

//// problem3:
//class Solution {
//	std::vector<std::pair<int,int>> result;
//	int result_length = std::numeric_limits<int>::max();
//public:
//	std::vector<pair<int,int>> merge(std::vector<pair<int, int>>  ranges, std::pair<int, int>  insert_range) {
//		for (int idx = 0; idx < ranges.size(); ) {
//			if (ranges[idx].first > insert_range.second||insert_range.first>ranges[idx].second) {
//				++idx;
//				continue;
//			}
//			else {
//				insert_range.first = std::min(ranges[idx].first, insert_range.first);
//				insert_range.second = std::max(ranges[idx].second, insert_range.second);
//				ranges.erase(ranges.begin() + idx);
//			}
//		}
//		ranges.emplace_back(insert_range);
//		return ranges;
//	}
//	vector<string> maxNumOfSubstrings(string s) {
//		std::vector<std::pair<int, int>> substr_idxs;
//		for (int idx = 0; idx < 26; ++idx) {
//			int begin = s.find_first_of('a' + idx);
//			int end = s.find_last_of('a' + idx);
//			if (begin == string::npos) {
//				continue;
//			}
//			else {
//				substr_idxs = merge(substr_idxs, std::pair<int, int>(begin, end));
//			}
//		}
//		for (int length = 1; length <= substr_idxs.size(); ++length) {
//			//std::vector<int> cur_range;
//			std::vector<std::pair<int, int>>cur_range;
//
//			find_result(length, substr_idxs,0,cur_range);
//			//if (result.size() != length) {
//			//	break;
//			//}
//		}
//		std::vector<string> ans;
//		for (auto &range : result) {
//			ans.emplace_back(s.substr(range.first, range.second - range.first + 1));
//		}
//		return ans;
//	}
//	void find_result(int length,std::vector<pair<int,int>>& all_range, int idx,std::vector<std::pair<int, int>> cur_range) {
//		if (idx == length) {
//			if (result.size() < cur_range.size()) {
//				result = cur_range;
//				int cur_lenght = 0;
//				for (int idx = 0; idx < cur_range.size(); ++idx) {
//					cur_lenght += cur_range[idx].second - cur_range[idx].first + 1;
//				}
//				result_length= cur_lenght;
//			}
//			else if (result.size() == cur_range.size()) {
//				int cur_char_num = 0;
//				for (int idx = 0; idx < length; ++idx) {
//					cur_char_num += all_range[idx].second - all_range[idx].first + 1;
//				}
//				if (result_length > cur_char_num) {
//					result =cur_range;
//					result_length = cur_char_num;
//				}
//			}
//			return;
//		}
//		for (int cur = idx; cur < all_range.size(); ++cur) {
//			std::swap(*(all_range.begin() + idx), *(all_range.begin() + cur));
//			auto added_ranges = merge(cur_range, all_range[idx]);
//			find_result(length, all_range, idx + 1, added_ranges);
//			std::swap(*(all_range.begin() + idx), *(all_range.begin() + cur));
//			//bool is_confict = false;
//			//for (int pre = idx - 1; pre >= 0; --pre) {
//			//	if (all_range[pre].first > all_range[cur].second || all_range[pre].second < all_range[cur].first) {
//			//		continue;
//			//	}
//			//	else {
//			//		is_confict = true;
//			//		break;
//			//	}
//			//}
//			//if (is_confict) {
//			//	continue;
//			//}
//			//else {
//			//	std::swap(*(all_range.begin() + idx), *(all_range.begin() + cur));
//			//	auto added_ranges=merge(cur_range, all_range[idx]);
//			//	find_result(length, all_range,idx + 1, added_ranges);
//			//	std::swap(*(all_range.begin() + idx), *(all_range.begin() + cur));
//			//}
//		}
//	}
//};

//If we find a valid substring, and then another valid substring within the first substring - we can ignore the larger substring.
//E.g. if we find "abccba", and then "bccb", and then "cc", we only care about "cc". This can be easily proven by a contradition.
//First, collect left (l) and right(r) indices for every character.
//Then, go through the string. If the current index i is the left index for the character s[i], it may be a valid substring.
//We then use a sliding window pattern to find the lendth of the substring.
//If we find a character that appears before i - we do not have a valid string starting at i.
//If substring is valid, we remember it, as well as it's right edge.
//This logic, repeated, will ensure that we find the valid substring with the smallest right edge.
//If the valid substring starts after the previous right edge, there is no overlap. The previous substring should be included into the result.
class Solution {
public:
	int checkSubstr(string &s, int i, vector<int> &l, vector<int> &r) {
		int right = r[s[i] - 'a'];
		for (auto j = i; j <= right; ++j) {
			if (l[s[j] - 'a'] < i)
				return -1;
			right = max(right, r[s[j] - 'a']);
		}
		return right;
	}
	vector<string> maxNumOfSubstrings(string s) {
		vector<int> l(26, INT_MAX), r(26, INT_MIN);
		vector<string> res(1);
		for (auto i = 0; i < s.size(); ++i) {
			l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
			r[s[i] - 'a'] = max(r[s[i] - 'a'], i);
		}
		auto right = INT_MAX;
		for (auto i = 0; i < s.size(); ++i) {
			if (i == l[s[i] - 'a']) {
				auto new_right = checkSubstr(s, i, l, r);
				if (new_right != -1) {
					if (i > right)
						res.push_back("");
					right = new_right;
					res.back() = s.substr(i, right - i + 1);
				}
			}
		}
		return res;
	}
};
int main() {
	/*std::vector<std::vector<int>> edges = { {0, 2}, {0, 3}, {1, 2} };
	int n = 4;
	string label = "aeed";
	auto ans = Solution2_2().countSubTrees(n, edges, label);
*/
	std::vector<std::vector<int>> edges = { { 0, 2 },{ 0, 3 },{ 1, 2 } };
	std::swap(*edges.begin(), *(edges.begin() + 1));
	auto ans=Solution().maxNumOfSubstrings("abab");
	cin.get();
	return 0;
}