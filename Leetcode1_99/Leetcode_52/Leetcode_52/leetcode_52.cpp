#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		std::vector<std::pair<int, int>> sol;
		int num = 0;
		queenSolver(num,sol, n);
		return num;
	}
	void queenSolver(int & num, std::vector<std::pair<int, int>> & sol, int queen_num) {
		if (queen_num == sol.size()) {
			++num;
			return;
		}
		for (int col = 0; col < queen_num; ++col) {
			int row = sol.size();
			bool if_contradic = false;
			for (int stone_idx = 0; stone_idx < sol.size(); ++stone_idx) {
				if (sol[stone_idx].first == row || sol[stone_idx].second == col || (abs(sol[stone_idx].first - row) == abs(sol[stone_idx].second - col))) {
					if_contradic = true;
					break;
				}
			}
			if (!if_contradic) {
				sol.emplace_back(row, col);
				queenSolver(num, sol, queen_num);
				sol.pop_back();
			}
		}
	}
};

int main() {
	Solution sol;
	std::cout<<sol.totalNQueens(4);
	std::cin.get();
	return 0;
}
