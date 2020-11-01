#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>
#include<unordered_map>
#include<map>
#include<set>


using namespace std;

class Solution {
public:
	bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
		for (int arr_idx = 0; arr_idx < arr.size();) {
			int word_idx = 0;
			for (; word_idx < pieces.size(); ++word_idx) {
				if (pieces[word_idx].front() == arr[arr_idx]) {
					//++arr_idx;
					int idx = 0;
					for (idx = 0; idx < pieces[word_idx].size(); ++idx) {
						if (arr_idx<arr.size()&&pieces[word_idx][idx] == arr[arr_idx]) {
							++arr_idx;
							continue;
						}
						else {
							break;
						}
						//else if(arr_idx==arr.size()){
						//	return false;
						//}
						//else {
						//	return false;
						//}
					}
					if (pieces[word_idx].size() != idx) {
						return false;
					}
					else {
						break;
					}
				}
			}
			if (word_idx == pieces.size()) {
				return false;
			}

		}
		return true;
	}
};

class Solution2 {
public:
	int countVowelStrings(int n) {
		std::vector<int> end_num(5, 1);
		for (int idx = 1; idx < n; ++idx) {	
			end_num[4] = end_num[0] + end_num[1] + end_num[2] + end_num[3] + end_num[4];
			end_num[3] = end_num[0] + end_num[1] + end_num[2] + end_num[3];
			end_num[2] = end_num[0] + end_num[1] + end_num[2];
			end_num[1] = end_num[0] + end_num[1];
			end_num[0] = end_num[0];
		}
		int result = 0;
		for (auto & ele : end_num) {
			result += ele;
		}
		return result;
	}
};


class Solution3 {
public:
	int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
		int result = 0;
		std::map<int,int> filled_gap2freq;
		for (; result < heights.size()-1; ++result) {
			int gap = heights[result + 1] - heights[result];
			if (gap > 0) {
				if (bricks >= gap) {
					bricks -= gap;
					++filled_gap2freq[gap];
				}
				else if (ladders > 0) {
					--ladders;
					if (filled_gap2freq.empty()) {
						continue;
					}
					auto  max_filled = filled_gap2freq.rbegin();
					if (max_filled->first <= gap) {

					}
					else {
						bricks += max_filled->first-gap;
						--filled_gap2freq[max_filled->first];
						//--max_filled->second
						if (filled_gap2freq[max_filled->first] == 0) {
							filled_gap2freq.erase(max_filled->first);
						}
						
					}
				}
				else {
					break;
				}
			}
		}
		return result;
	}
};

int main() {
	//std::cout << Solution2().countVowelStrings(1);
	std::vector<int> arr = { 15,88 };
	std::vector<std::vector<int>> pieces{ { 16,18,49 }};
	std::cout << Solution().canFormArray(arr, pieces);

	//std::vector<int> heights{ 4,12,2,7,3,18,20,3,19 };
	//int bricks = 10;
	//int ladders = 2;
	//std::cout << Solution3().furthestBuilding(heights, bricks, ladders);
	cin.get();
	return 0;
}