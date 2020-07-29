#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		std::vector<std::vector<string>> result;
		std::vector<std::pair<int, int>> sol;
		queenSolver(result, sol, n);
		return result;
	}
	void queenSolver(std::vector<vector<string>> & result, std::vector<std::pair<int,int>> & sol, int queen_num) {
		if (queen_num == sol.size()) {
			std::vector<string> regulared_sol(queen_num, string(queen_num, '.'));
			for (auto & ele : sol) {
				regulared_sol[ele.first][ele.second] = 'Q';
			}
			result.emplace_back(regulared_sol);
			return ;
		}
		for (int col = 0; col < queen_num; ++col) {
			int row = sol.size();
			bool if_contradic = false;
			for (int stone_idx = 0; stone_idx < sol.size(); ++stone_idx) {
				if (sol[stone_idx].first == row || sol[stone_idx].second==col || (abs(sol[stone_idx].first - row) == abs(sol[stone_idx].second - col))) {
					if_contradic = true;
					break; 
				}
			}
			if (!if_contradic) {
				sol.emplace_back(row, col);
				queenSolver(result, sol, queen_num);
				//if col in [0,queen_num) all contradicts, then pop the last stone and go on;
				sol.pop_back();
			}
		}
	}
};

int main() {
	Solution sol;
	auto ans = sol.solveNQueens(8);
	for (auto & sol : ans) {
		for (auto & row : sol) {
			std::cout << row << std::endl;
		}
		std::cout << std::endl;
	}
	std::cin.get();
	return 0;
}