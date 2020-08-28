#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// method: DFS (TLE)
// time complexity: O(3^N), N is the day number;
// space complexity: O(N);
class Solution1 {
	int m_result = 0;
	std::vector<int> tickets;
	std::vector<int> m_days;
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		m_result =std::numeric_limits<int>::max();
		tickets = costs;
		m_days = days;
		int cur_day = days.front();
		int cur_cost = 0;
		dfs(cur_day, cur_cost);
		return m_result;
	}
private:
	void dfs(int cur_day, int cur_cost) {
		if (cur_cost > m_result) {
			return;
		}
		if (cur_day > m_days.back()) {
			if (cur_cost < m_result) {
				m_result = cur_cost;
			}
			return;
		}
		auto first_greater = std::lower_bound(m_days.begin(), m_days.end(), cur_day + 1);
		if (first_greater != m_days.end()) {
			dfs(*first_greater, cur_cost + tickets[0]);
		}
		else {
			if (cur_cost + tickets[0] < m_result) {
				m_result = cur_cost + tickets[0];
			}
		}
		first_greater = std::lower_bound(m_days.begin(), m_days.end(), cur_day + 7);
		if (first_greater != m_days.end()) {
			dfs(*first_greater, cur_cost + tickets[1]);
		}
		else {
			if (cur_cost + tickets[1] < m_result) {
				m_result = cur_cost + tickets[1];
			}
		}
		first_greater = std::lower_bound(m_days.begin(), m_days.end(), cur_day + 30);
		if (first_greater != m_days.end()) {
			dfs(*first_greater, cur_cost + tickets[2]);
		}
		else {
			if (cur_cost + tickets[2] < m_result) {
				m_result = cur_cost + tickets[2];
			}
		}
	}
};

// method2: dfs + memorization;
// dp[i] indicates the minimum cost for dayi to day365;
// time complexity: O(N), N is the day number;
// space complexity: O(N);
class Solution2 {
	std::vector<int> dp;
	std::vector<int> m_days;
	std::vector<int> m_cost;
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		dp.resize(366, -1);
		dp[0] = 0;
		m_days = days;
		m_cost = costs;
		find_cost(days.front());
		return dp[days.front()];
	}
private:
	int find_cost(int day) {
		if (day > m_days.back()) {
			return 0;
		}
		if (dp[day] != -1) {
			return dp[day];
		}

		auto find_ele = std::lower_bound(m_days.begin(), m_days.end(), day);
		if (find_ele == m_days.end() || (*find_ele) != day) {
			dp[day] = find_cost(day + 1);
		}
		else {
			dp[day] = std::min({find_cost(day + 1) + m_cost[0], find_cost(day + 7) + m_cost[1],\
				find_cost(day + 30) + m_cost[2]});
		}
		return dp[day];
	}
};

// solution3: use flag vector to replace the binary seach of whether going out is required at a day;
class Solution {
	std::vector<int> dp;
	std::vector<int> m_days;
	std::vector<int> m_cost;
	// the flag to record whether to go out at a day;
	std::vector<int> m_is_out;
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		dp.resize(366, -1);
		m_is_out.resize(365, 0);
		for (auto & ele : days) {
			m_is_out[ele - 1] = 1;
		}
		dp[0] = 0;
		m_days = days;
		m_cost = costs;
		find_cost(days.front());
		return dp[days.front()];
	}
private:
	int find_cost(int day) {
		if (day > m_days.back()) {
			return 0;
		}
		if (dp[day] != -1) {
			return dp[day];
		}

		auto find_ele = std::lower_bound(m_days.begin(), m_days.end(), day);
		if (!m_is_out[day-1]) {
			dp[day] = find_cost(day + 1);
		}
		else {
			dp[day] = std::min({ find_cost(day + 1) + m_cost[0], find_cost(day + 7) + m_cost[1],\
				find_cost(day + 30) + m_cost[2] });
		}
		return dp[day];
	}
};

int main() {
	std::vector<int> test_vec{1,4,6,7,8,365};
	std::vector<int> cost{ 2,7,15};
	std::cout << Solution().mincostTickets(test_vec, cost);
	cin.get();
	return 0;
}