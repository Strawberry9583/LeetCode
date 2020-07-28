#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<bitset>


using namespace std;

// firstly, put the most frequent element in gap n;
// secondly, if the amount elements >= n+1; then return tasks.size(), because other elements can be inserted directly;
// thirdly, if the amount elements < n+1; then maybe there are idle times, so calc the idle times;
// so put the other most frequent elements, empty_pos_in_every_frame = n - (max_freq_num - 1);
// non_max_freq_task_cost = tasks.size() - max_freq_num * max_freq;
// idle_time = empty_pos_in_every_frame * (max_freq - 1) - non_max_freq_task_cost;
// but the idle time maybe < 0, in the case the empty pos is not enought to put non-most frequent elements;


class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		if (tasks.empty()) {
			return 0;
		}
		unordered_map<char, int>task2num;
		int max_freq = std::numeric_limits<int>::lowest();
		int max_freq_num = 1;
		for (auto & ele : tasks) {
			++task2num[ele];
			if (max_freq < task2num[ele]) {
				max_freq = task2num[ele];
				max_freq_num = 1;
			}
			else if (max_freq == task2num[ele]) {
				++max_freq_num;
			}
		}
		if (max_freq_num - 1 >= n) {
			return tasks.size();
		}
		else {
			int empty_pos_in_every_frame = n - (max_freq_num - 1);
			int non_max_freq_task_cost = tasks.size() - max_freq_num * max_freq;
			int idle_time = empty_pos_in_every_frame * (max_freq - 1) - non_max_freq_task_cost;
			if (idle_time > 0) {
				return tasks.size() + idle_time;
			}
			else {
				return tasks.size();
			}
		}

	}
};


int main() {
	std::vector<char>tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	int  n = 1;
	std::cout << Solution().leastInterval(tasks, n);
	cin.get();
	return 0;
}