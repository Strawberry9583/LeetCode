#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;


// solution 1:use map to counter the frequency of the char then sort char by their freqeuncy;
// Time complexity: O(n*logn), Space complexity:O(n);
class Solution {
public:
	string frequencySort(string s) {
		//ios::sync_with_stdio(false); cin.tie(0);
		//count the  frequency;
		unordered_map<char, int> char2num;
		for (auto & ele : s) {
			++char2num[ele];
		}
		//sort the frequency;
		std::vector<pair<char, int>> charandnum;
		for (auto & ele : char2num) {
			charandnum.emplace_back(ele);
		}
		sort(charandnum.begin(), charandnum.end(), [](const std::pair<char, int> & rhs1, const std::pair<char, int> &rhs2)->bool
		{return rhs1.second > rhs2.second; });
		//cntr the result with char and its frequency;
		string result;
		for (auto & ele : charandnum) {
			result += string(ele.second, ele.first);
		}
		return result;
	}
};

// solution 2: with bucket sort, reduce the time complexity but the may cost larger space to construct bucket;
// Time complexity: O(n), Space complexity:O(n);

class Solution2 {
public:
	string frequencySort(string s) {
		//ios::sync_with_stdio(false); cin.tie(0);
		//count the  frequency;
		unordered_map<char, int> char2num;
		for (auto & ele : s) {
			++char2num[ele];
		}
		//bucket idx indicates the length of the char (actually the frequency)
		std::vector<string> bucket(s.size() + 1, "");
		//add the char to the conresponding bucket;
		for (auto & ele : char2num) {
			bucket[ele.second] += string(ele.second, ele.first);
		}
		//sum up the result reversely;
		string result;
		for (auto idx = bucket.rbegin(); idx != bucket.rend(); ++idx) {
			if (!idx->empty()) {
				result += *idx;
			}
		}
		return result;
	}
};

int main() {

	cin.get();
	return 0;
}