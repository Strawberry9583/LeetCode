#include<iostream>
#include<stack>
#include<vector>


using namespace std;

// method1: monotonous stack;
// time complexity: O(n); space complexity: O(n);
class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		std::stack<int> size_sta;
		int idx = 0;
		while (idx<asteroids.size()) {
			if (size_sta.empty()) {
				size_sta.emplace(asteroids[idx]);
				++idx;
			}
			else {
				if (size_sta.top()*asteroids[idx] < 0&&size_sta.top()>0) {
					if (std::abs(size_sta.top()) > std::abs(asteroids[idx])) {
						++idx;
					}
					else if (std::abs(size_sta.top()) < std::abs(asteroids[idx])) {
						size_sta.pop();
					}
					else {
						size_sta.pop();
						++idx;
					}
				}
				else {
					size_sta.emplace(asteroids[idx]);
					++idx;
				}
			}
		}
		std::vector<int> result;
		while (!size_sta.empty()) {
			result.emplace_back(size_sta.top());
			size_sta.pop();
		}
		std::reverse(result.begin(), result.end());
		return result;
	}
};


int main() {
	std::vector<int> size_vec{ 10,2,-5};
	auto ans = Solution().asteroidCollision(size_vec);
	for (auto & ele : ans) {
		std::cout << ele << " ";
	}
	cin.get();
	return 0;
}