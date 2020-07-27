#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<functional>
#include<tuple>
#include<unordered_set>
using namespace std;

class Solution1 {
public:
	int maxScore(string s) {
		int zero_num = 0;
		int one_num=0;
		for (auto & ele : s) {
			if (ele == '0') {
				++zero_num;
			}
			else {
				++one_num;
			}
		}
		int cur_value;
		int left_zero = 0, right_one = one_num;
		if (s[0] == '0') {
			left_zero = 1;
		}
		else {
			right_one = one_num - 1;
		}
		int max_value = left_zero+right_one;
		for (int idx = 1; idx < s.size() - 1; ++idx) {
			if (s[idx] == '0') {
				++left_zero;
			}
			else {
				--right_one;
			}
			if (left_zero + right_one > max_value) {
				max_value = left_zero + right_one;
			}
		}
		return max_value;
	}
};

//solution 1: TLE;
class Solution2_1 {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		if (cardPoints.empty() || k < 1) {
			return 0;
		}
		return max_score(cardPoints,0,cardPoints.size()-1,k);
	}
	long int max_score(std::vector<int>& points, int left, int right, int left_card) {
		if (left_card == 1) {
			return std::max(points[left], points[right]);
		}
		else {
			return std::max(points[left] + max_score(points, left + 1, right, left_card - 1),
				points[right] + max_score(points, left, right - 1, left_card - 1));
		}
	}
};

//use map to record the optima that have been calculated;
class Solution2_2 {
private:

	std::unordered_map<string, int> m_case2maxscore;
public:
	int maxScore(vector<int>& cardPoints, int k) {
		if (cardPoints.empty() || k < 1) {
			return 0;
		}
		//auto compare = [](const std::pair<int, int> & rhs1, const std::pair<int, int> & rhs2) {
		//	return rhs1.first == rhs2.first&&rhs1.second == rhs2.second; };

		return max_score(cardPoints, 0, cardPoints.size() - 1, k);
	}
	long int max_score(std::vector<int>& points, int left, int right, int left_card) {
		string key = to_string(left) + " " + to_string(right);
		auto find_score = m_case2maxscore.find(key);
		if (find_score != m_case2maxscore.end()) {
			return find_score->second;
		}
		else {
			if (left_card ==1) {
				m_case2maxscore[key] = std::max(points[left],points[right]);
			}
			else {
				m_case2maxscore[key] = std::max(points[left] + max_score(points, left + 1, right, left_card - 1),
					points[right] + max_score(points, left, right - 1, left_card - 1));
			}
			return m_case2maxscore[key];
		}
	}
};

//divide the sum into left_most sum and right_most sum;
//then slides the boundary to get check the cur_max_sum;
class Solution2_3 {
private:
public:
	int maxScore(vector<int>& cardPoints, int k) {
		if (cardPoints.empty() || k < 1) {
			return 0;
		}
		int left_sum = 0;
		int right_sum = 0;
		for (int idx = 0; idx < k; ++idx) {
			right_sum += cardPoints[cardPoints.size() - 1 - idx];
		}
		int result = left_sum + right_sum;
		for (int idx = 0; idx < k; ++idx) {
			left_sum += cardPoints[idx];
			right_sum -= cardPoints[cardPoints.size() - k + idx];
			if (result < left_sum + right_sum) {
				result = left_sum + right_sum;
			}
		}
		return result;
	}
};

//class Solution {
//public:
//	vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
//		std::vector<int> result;
//		for (int row = 0; row < nums.size(); ++row) {
//			for (int idx = row; idx >= 0; --idx) {
//				int col = row - idx;
//				if (col < nums[idx].size()) {
//					result.emplace_back(nums[idx][col]);
//				}
//				else {
//					continue;
//				}
//			}
//		}
//		for (int idx = 0; idx < nums.size() - 1; ++idx) {
//			int star_row = nums.size() - 1;
//			int start_col = idx + 1;
//			for (int num=idx; num<nums.size()-1; ++num) {
//				int row_x = star_row -( num - idx);
//				int col_y = start_col + (num - idx);
//				if (col_y < nums[row_x].size()) {
//					result.emplace_back(nums[row_x][col_y]);
//				}
//				else {
//					continue;
//				}
//			}
//		}
//
//		return result;
//	}
//};

//Time limited exceed;
class Solution3_1 {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
		int max_size = nums.size();
		for (const auto & ele : nums) {
			if (ele.size() > max_size) {
				max_size = ele.size();
			}
		}
		std::vector<int>result;
		for (int row_idx = 0; row_idx < max_size; ++row_idx) {
			int start_row = row_idx;
			int start_col = 0;
			for (int col_idx = 0; col_idx < max_size; ++col_idx) {
				int row = start_row - col_idx;
				int col = start_col + col_idx;
				if (row >= 0 && row < nums.size() && col >= 0 && col < nums[row].size()) {
					result.emplace_back(nums[row][col]);
				}
				else {
					continue;
				}
			}
		}
		for (int row_idx = 0; row_idx < max_size - 1; ++row_idx) {
			int start_row = max_size-1;
			int start_col = 1 + row_idx;
			for (int col_idx = 0; col_idx < max_size; ++col_idx) {
				int row = start_row - col_idx;
				int col = start_col + col_idx;
				if (row >= 0 && row < nums.size() && col >= 0 && col < nums[row].size()) {
					result.emplace_back(nums[row][col]);
				}
				else {
					continue;
				}
			}
		}
		return result;
	}
};
//sort the element according to their index sum
// following n indicates the amount of all elements in nums;
//time complexity:O(nlogn);
//space complexity: O(n);
class Solution3_2 {
public:
	struct comp {
		bool operator()(const std::tuple<int, int, int> & rhs1, const std::tuple<int, int, int>& rhs2) 			{
			if (std::get<0>(rhs1) + std::get<1>(rhs1) == std::get<0>(rhs2) + std::get<1>(rhs2)) {
				return std::get<0>(rhs1) > std::get<0>(rhs2);
			}
			else {
				return std::get<0>(rhs1) + std::get<1>(rhs1) < std::get<0>(rhs2) + std::get<1>(rhs2);
			}
		}
	};

	vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
		//auto hash_func = [](std::tuple<int, int, int> & obj) 
		//{ return std::hash<int>()(std::get<0>(obj)) + std::hash<int>()(std::get<1>(obj)); };
		//auto key_equal = [](const std::tuple<int, int, int> & rhs1,const std::tuple<int,int,int>& rhs2)
		//{return get<0>(rhs1)==get<0>(rhs }
		//std::unordered_set<std::tuple<int,int,int>,decltype(hash_func),> 
		std::vector<tuple<int, int, int>> num_data;
		for (int row = 0; row < nums.size(); ++row) {
			for (int col = 0; col < nums[row].size(); ++col) {
				num_data.emplace_back(row, col, nums[row][col]);
			}
		}
		std::sort(num_data.begin(), num_data.end(), comp());
		std::vector<int>result;
		for (const auto & ele : num_data) {
			result.emplace_back(std::get<2>(ele));
		}
		return result;
	}
};

//insert all elements into the same bucket with same sum of row and col idx;
//then reverse the elements in the same bucket, cause that: 
// the element with larger row idx should in the front;
//Time complexity: O(n);
//Space complexity; O(n);
class Solution3_3 {
public:

	vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
		// key (row_idx+col_idx) to bucket;
		std::unordered_map<int, std::vector<int>> sum2nums;
		int max_key = std::numeric_limits<int>::lowest();
		for (int row = 0; row < nums.size(); ++row) {
			for (int col = 0; col < nums[row].size(); ++col) {
				sum2nums[row + col].emplace_back(nums[row][col]);
				if (max_key < row + col) {
					max_key = row + col;
				}
			}
		}
		
		std::vector<int>result;
		for (int key = 0; key <= max_key; ++key) {
			auto find_key = sum2nums.find(key);
			//reversely push the element;
			//because the element with larger row idx should in the front
			if ( find_key!= sum2nums.end()) {
				for (auto ele = find_key->second.rbegin(); ele != find_key->second.rend(); ++ele) {
					result.emplace_back(*ele);
				}
			}
		}
		return result;
	}
};

//use vector to replace map of solution 3;
//Time complexity: O(n);
//Space complexity; O(n);
class Solution3_4 {
public:

	vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
		int max_size = nums.size();
		for (auto & ele : nums) {
			if (max_size < ele.size()+max_size) {
				max_size = ele.size()+max_size;
			}
		}
		// key (row_idx+col_idx) to bucket;
		std::vector<std::vector<int>> sum2bucket(max_size,std::vector<int>());
		for (int row = 0; row < nums.size(); ++row) {
			for (int col = 0; col < nums[row].size(); ++col) {
				sum2bucket[row + col].emplace_back(nums[row][col]);
			}
		}
		//reversly insert the element;
		std::vector<int>result;
		for (auto & bucket : sum2bucket) {
			result.insert(result.end(), bucket.rbegin(), bucket.rend());
		}
		return result;
	}
};
int main() {
	//Solution sol;
	//std::vector<int> test{ 1,2,3 };
	//std::cout << sol.maxScore(test, 3);
	Solution2_3 sol;
	std::vector<int> test{ 1,2,3,4,5,6,1 };
	std::cout<<sol.maxScore(test,3);

	std::cin.get();
	return 0;
}