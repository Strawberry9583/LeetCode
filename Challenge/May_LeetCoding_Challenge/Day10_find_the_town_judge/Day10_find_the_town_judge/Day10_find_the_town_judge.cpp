#include<vector>
#include<iostream>
#include<deque>
using namespace std;

class Solution_1 {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		std::deque<bool> judge_flag(N+1, true);
		for (auto & ele : trust) {
			judge_flag[ele[0]] = false;
		}
		std::vector<int> judge;
		for (int idx = 1; idx <= N; ++idx) {
			if (judge_flag[idx]) {
				judge.emplace_back(idx);
				if (judge.size() > 1) {
					return -1;
				}
			}
		}
		if (judge.size() != 1) {
			return -1;
		}
		judge_flag.assign(N+1, false);
		int trust_num = 0;
		for (auto & ele : trust) {
			if (ele[1] == judge.front()&&(!judge_flag[ele[0]]) && (ele[0] != judge.front())) {
				++trust_num;
				judge_flag[ele[0]] = true;
				if (trust_num > N - 1) {
					return -1;
				}
			}
		}
		return trust_num == N - 1 ? judge.front() : -1;
	}
};


//calc the in and out degree of every person;
//then return the person with in degree==N-1, and out degree==0;
class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		
		std::vector<std::pair<int, int>> in_out_num(N + 1, std::pair<int, int>(0, 0));
		for (const auto & ele : trust) {
			++in_out_num[ele[1]].first;
			++in_out_num[ele[0]].second;
		}
		std::vector<int> judge;
		for (int idx = 1; idx <= N; ++idx) {
			if (in_out_num[idx].first == N - 1&&in_out_num[idx].second==0) {
				judge.emplace_back(idx);
				if (judge.size() > 1) {
					return -1;
				}
			}
		}
		return judge.size() == 1 ? judge.front() : -1;
	}
};
int main() {
	std::vector<std::vector<int>> test{ {1,3},{2,3},{3,1} };
	std::cout << Solution().findJudge(3,test);
	std::cin.get();
	return 0;
}