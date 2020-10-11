#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution1 {
public:
	int maxDepth(string s) {
		int result = 0, cur = 0;
		for (auto & ele : s) {
			if (ele == '(') {
				++cur;
				if (result < cur) {
					result = cur;
				}
			}
			else if (ele == ')') {
				--cur;
			}
		}
		return result;
	}
};

class Solution2 {
public:
	int maximalNetworkRank(int n, vector<vector<int>>& roads) {
		std::vector<std::pair<int, int>> city2road(n, { 0,0 });
		for (int idx = 0; idx < n; ++idx) {
			city2road[idx].second = idx;
		}
		std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));
		for (const auto & road : roads) {
			++city2road[road[0]].first;
			++city2road[road[1]].first;
			graph[road[0]][road[1]] = 1;
			graph[road[1]][road[0]] = 1;
		}
		int result = 0;
		for (int node1 = 0; node1 < n; ++node1) {
			for (int node2 = node1 + 1; node2 < n; ++node2) {
				int temp = city2road[node1].first + city2road[node2].first;
				if (graph[node1][node2]) {
					--temp;
				}
				if (temp > result) {
					result = temp;
				}
			}
		}

		return result;
	}
};


class Solution3_1 {
public:
	bool checkPalindromeFormation(string a, string b) {
		if (checkPalindrome(a) || checkPalindrome(b)) {
			return true;
		}
		if (checkSubPalindrome(a, b)||checkSubPalindrome(b,a)) {
			return true;
		}
		std::reverse(a.begin(), a.end());
		std::reverse(b.begin(), b.end());
		if (checkSubPalindrome(a, b)) {
			return true;
		}
		return false;
	}
private:
	bool checkSubPalindrome(const string & s1, const string &s2) {
		int left_size = 1;
		while (left_size - 1<=s2.size() - left_size) {
			if (s1[left_size - 1] == s2[s2.size() - left_size]) {
				if (left_size + left_size + 1 >= s2.size()) {
					return true;
				}
			}
			else {
				break;
			}
			++left_size;
		}
		int max_length = left_size;
		bool result = true;
		while (max_length-1<=s2.size()-max_length) {
			if (s2[max_length - 1] != s2[s2.size() - max_length]) {
				result = false;
				break;
			}
			++max_length;
		}
		if (result) {
			return true;
		}
		max_length = left_size;
		while (max_length - 1 <= s2.size() - max_length) {
			if (s1[max_length - 1] != s1[s2.size() - max_length]) {
				return false;
			}
			++max_length;
		}
		return true;
	}
	bool checkPalindrome(const string& s) {
		int left = 0, right = s.size() - 1;
		while (left<right) {
			if (s[left++] != s[right++]) {
				return false;
			}
		}
		return true;
	}
};

class Solution3_2 {
public:
	bool isPalindrome(string &s, int i, int j) {
		while (i < j && s[i] == s[j])
			++i, --j;
		return i >= j;
	}
	bool check(string &a, string &b) {
		int i = 0, j = a.size() - 1;
		while (i < j && a[i] == b[j])
			++i, --j;
		return isPalindrome(a, i, j) || isPalindrome(b, i, j);
	}
	bool checkPalindromeFormation(string a, string b) {
		return check(a, b) || check(b, a);
	}

};

int main() {
	//std::vector<std::vector<int>> roads = {{0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 4}};
	//int n = 5;
	//std::cout << Solution2().maximalNetworkRank(n, roads);
	string a = "aejbaalflrmkswrydwdkdwdyrwskmrlfqizjezd", b = "uvebspqckawkhbrtlqwblfwzfptanhiglaabjea";
	std::cout << Solution3_2().checkPalindromeFormation(a, b);
	cin.get();
	return 0;
}