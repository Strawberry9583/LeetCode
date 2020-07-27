#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// solution 1: different cases uses different range bound;
class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
		int cur_a = 0, cur_b = 0;
		std::vector<std::vector<int>> result;
		while (cur_a<A.size() && cur_b<B.size()) {
			if (A[cur_a][0] >= B[cur_b][0] && A[cur_a][0] <= B[cur_b][1]) {
				if (A[cur_a][1] <= B[cur_b][1]) {
					result.emplace_back(std::vector<int>{A[cur_a][0], A[cur_a][1]});
					++cur_a;
				}
				else {
					result.emplace_back(std::vector<int>{A[cur_a][0], B[cur_b][1]});
					++cur_b;
				}
			}
			else if (A[cur_a][0] > B[cur_b][1]) {
				++cur_b;
			}
			else {
				if (A[cur_a][1] < B[cur_b][0]) {
					++cur_a;
				}
				else if (A[cur_a][1] >= B[cur_b][0] && A[cur_a][1] <= B[cur_b][1]) {
					result.emplace_back(std::vector<int>{B[cur_b][0], A[cur_a][1]});
					++cur_a;
				}
				else {
					result.emplace_back(std::vector<int>{B[cur_b][0], B[cur_b][1]});
					++cur_b;
				}
			}
		}
		return result;
	}
};

// solutin 2: similar to solution 1, but formulate the aboving cases into just one;
class Solution2 {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
		int cur_a = 0, cur_b = 0;
		std::vector<std::vector<int>> result;
		//decrease the cost when vector grows;
		result.reserve(A.size());
		while (cur_a<A.size() && cur_b<B.size()) {
			// formulate the aboving cases into just one;
			int bound_left = std::max(A[cur_a][0], B[cur_b][0]);
			int bound_right = std::min(A[cur_a][1], B[cur_b][1]);
			if (bound_left <= bound_right) {
				result.emplace_back(std::vector<int>{bound_left, bound_right});
			}
			if (A[cur_a][1] <= B[cur_b][1]) {
				++cur_a;
			}
			else {
				++cur_b;
			}
		}
		// reduce the vector memory;
		result.shrink_to_fit();
		return result;
	}
};
int main() {

	cin.get();
	return 0;
}