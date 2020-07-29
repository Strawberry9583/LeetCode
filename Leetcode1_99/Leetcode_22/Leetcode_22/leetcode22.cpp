//Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
//
//For example, given n = 3, a solution set is :
//
//[
//	"((()))",
//	"(()())",
//	"(())()",
//	"()(())",
//	"()()()"
//]



#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>


using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n == 0) {
			return result;
		}
		else {
			tuple<string, int, int, int> seed("(", n - 1, n, 1);
			auto temp = get_following(seed);
			for (int i = 1; i < 2*n-1; ++i) {
				
				auto temp_seed = temp.begin();
				decltype(temp) next_temp;
				next_temp.clear();
				while (temp_seed!=temp.end()) {
					auto get = get_following(*temp_seed);
					++temp_seed;
					next_temp.insert(next_temp.end(), get.begin(), get.end());
				}
				temp = next_temp;
			}
			for (auto i = temp.begin(); i != temp.end(); ++i) {
				result.push_back(get<0>(*i));
			}
			return result;
		}

	}
	vector<std::tuple<string, int, int, int> > get_following( tuple<string,int,int,int> & rhs ) {
		vector<std::tuple<string, int, int, int> > mid_result;
		//parenthesis can be added;
		if (std::get<3>(rhs) > 0) {
			// ( is added;
			if (get<1>(rhs) > 0) {
				mid_result.emplace_back(std::get<0>(rhs) + "(", std::get<1>(rhs) - 1,
					std::get<2>(rhs), std::get<3>(rhs)+1);
			}
			if (get<2>(rhs) > 0) {
				mid_result.emplace_back(std::get<0>(rhs) + ")", std::get<1>(rhs),
					std::get<2>(rhs)-1, std::get<3>(rhs) -1);
			}
		}
		//only ( can be added;
		else if (std::get<3>(rhs) == 0) {
			if (get<1>(rhs) > 0) {
				mid_result.emplace_back(std::get<0>(rhs) + "(", std::get<1>(rhs) - 1,
					std::get<2>(rhs), std::get<3>(rhs) + 1);
			}
		}
		return mid_result;
	}
};

int main() {
	Solution sol;
	auto result = sol.generateParenthesis(3);
	for (auto i = result.begin(); i != result.end(); ++i) {
		cout << *i << endl;
	}
	cin.get();
	return 0;
}