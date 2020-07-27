#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<array>
#include<set>
#include<unordered_set>
#include<map>
using namespace std;


class Solution1 {
public:
	string reformat(string s) {
		std::array<int, 10> digit2num;
		digit2num.fill(0);
		//digit2num.assign(0);
		std::array<int, 26> lower2num;
		lower2num.fill(0);
		int digitnum = 0;
		int lowernum = 0;
		for (auto & ele : s) {
			if (ele >= '0'&&ele <= '9') {
				++digit2num[ele - '0'];
				++digitnum;
			}
			else if (ele >= 'a'&&ele <= 'z') {
				++lower2num[ele - 'a'];
				++lowernum;
			}
		}
		if (std::abs(digitnum - lowernum) > 1) {
			return string();
		}
		string result;
		bool if_digit = digitnum > lowernum;
		int idx_digit = 0;
		int idx_lower= 0;
		while (digitnum>0 || lowernum>0) {
			if (if_digit) {
				for ( idx_digit = 0; idx_digit < digit2num.size(); ++idx_digit) {
					if (digit2num[idx_digit] > 0) {
						--digit2num[idx_digit];
						result += idx_digit + '0';
						--digitnum;
						if_digit = !if_digit;
						break;
					}
				}
			}
			else {
				for (idx_lower = 0; idx_lower < lower2num.size(); ++idx_lower) {
					if (lower2num[idx_lower] > 0) {
						--lower2num[idx_lower];
						result += idx_lower + 'a';
						--lowernum;
						if_digit = !if_digit;
						break;
					}
				}
			}
		}
		return result;
	}
};

class Solution2 {
public:
	vector<vector<string>> displayTable(vector<vector<string>>& orders) {
		std::map<int, std::map<string, int>> tablenum2foodeitem_num;
		std::set<string> fooditem_set;
		for (int order_idx = 0; order_idx < orders.size(); ++order_idx) {
			string table_name = orders[order_idx][1];
			int table_num = std::stoi(table_name);
			string food_item = orders[order_idx][2];
			if (fooditem_set.find(food_item) == fooditem_set.end()) {
				fooditem_set.insert(food_item);
			}
			++tablenum2foodeitem_num[table_num][food_item];
		}
		std::vector<std::vector<string>> result(tablenum2foodeitem_num.size()+1, std::vector<string>(fooditem_set.size() + 1, string()));
		std::vector<string> header;
		header.emplace_back("Table");
		for (auto & ele : fooditem_set) {
			header.emplace_back(std::move(ele));
		}
		result[0] = header;
		int row_idx = 1;
		for (auto & onetable : tablenum2foodeitem_num) {
			result[row_idx][0] = std::to_string(onetable.first);
			for (int col_idx = 1; col_idx < result[0].size(); ++col_idx) {
				auto num_find = onetable.second.find(result[0][col_idx]);
				if ( num_find== onetable.second.end()) {
					result[row_idx][col_idx] = "0";
				}
				else {
					result[row_idx][col_idx] = std::to_string(num_find->second);
				}
			}
			++row_idx;

		}
		return result;
		//for (int row = 1; row < result.size(); ++row) {
		//	result[row][0]=
		//	for(int col=1;col<result)
		//}
	}
};

//class Solution {
//public:
//	int minNumberOfFrogs(string croakOfFrogs) {
//		int result = -1;
//		int pre_idx = -1;
//		int cur_idx = -1;
//		int start_idx = 0;
//		while (start_idx>=croakOfFrogs.size()-1) {
//			
//		}
//
//	}
//};

int main() {
	Solution sol;
	//std::vector<std::vector<string>> test_case = {{"David", "3", "Ceviche"}, {"Corina", "10", "Beef Burrito"}, {"David", "3", "Fried Chicken"}, {"Carla", "5", "Water"}, {"Carla", "5", "Ceviche"}, {"Rous", "3", "Ceviche"}};
	//auto ans = sol.displayTable(test_case);
	//std::cout << sol.reformat(string("covid2019"));

	std::cin.get();
	return 0;
}