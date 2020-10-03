#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<functional>

using namespace std;



class Solution1_1 {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		if (timeSeries.empty() || duration == 0) {
			return 0;
		}
		int result = duration;
		int cur_time = timeSeries.front() + duration;
		while (cur_time < timeSeries.back() + duration) {
			auto first_le = std::lower_bound(timeSeries.begin(), timeSeries.end(), cur_time);
			if ((*(first_le - 1)) + duration == cur_time) {
				cur_time = (*first_le) + duration;
				result += duration;
			}
			else {
				int temp = (*(first_le - 1)) + duration;
				result += temp - cur_time;
				cur_time = temp;
			}
		}
		return result;
	}
};

class Solution1_2 {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		int ans = 0;
		int curr = 0;
		int n = timeSeries.size();
		for (int i = 0; i < n; i++) {
			int temp = timeSeries[i] + duration - max(curr, timeSeries[i]);
			ans += temp;
			curr = timeSeries[i] + duration;
		}
		return ans;
	}
};
int main() {
	//std::vector<int>customer{ 21, 1, 38, 42, 33, 16, 26, 26, 49, 3, 31, 37, 7, 43, 18, 46, 44, 27, 42, 16, 15, 29, 17, 7, 50, 20 };
	//std::vector<int> customer{ 8,3 };
	//int boardingcost = 5, runningcost = 6;
	//std::cout << Solution2().minOperationsMaxProfit(customer, boardingcost, runningcost);
	std::vector<int> timeseries{ 1,2,3,4,5,6,7,8,9 };
	int duration = 0;
	std::cout << Solution1_2().findPoisonedDuration(timeseries, duration);
	cin.get();
	return 0;
}