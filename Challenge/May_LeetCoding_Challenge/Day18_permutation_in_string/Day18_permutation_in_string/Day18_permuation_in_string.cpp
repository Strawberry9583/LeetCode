/* Leetcode 567: permuation in string
   https://leetcode.com/problems/permutation-in-string/solution/
*/


#include<vector>
#include<string>
#include<iostream>

using namespace std;

// solution1: record the occurance then slide the window by the same lenght of standard string;
// Space complexity: O(1), Time complexity: O(m+n);
// however every comparison cost 26 comparison;
class Solution1 {
public:
	bool checkInclusion(string s1, string s2) {
		std::vector<int> char2num(26, 0);
		for (int idx = 0; idx < s1.size(); ++idx) {
			++char2num[s1[idx] - 'a'];
		}
		int idx = 0;
		std::vector<int> temp(26, 0);
		while (idx<s2.size()) {
			++temp[s2[idx] - 'a'];
			if (idx >= s1.size()) {
				--temp[s2[idx-s1.size()] - 'a'];
			}
			if (char2num == temp) {
				return true;
			}
			++idx;
		}
		return false;
	}
};

// solution2: just update the char2num of changed; but not all the 26 types of chars' number;
// Space complexity: Space complexity: O(1), Time complexity: O(m+n);
// every comparison costs just one comparison, whether the count is equal to 26;
class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size()) {
			return false;
		}
		std::vector<int> char2num(26, 0);
		std::vector<int> tempnum(26, 0);
		for (int idx = 0; idx < s1.size(); ++idx) {
			++char2num[s1[idx] - 'a'];
			++tempnum[s2[idx] - 'a'];
		}

		int count = 0;
		for (int idx = 0; idx < 26; ++idx) {
			if (char2num[idx] == tempnum[idx]) {
				++count;
			}
		}
		//indicat the range of s2: [left,right];
		int left = 0, right = s1.size() - 1;
		while (right < s2.size()-1) {
			if (count == 26) {
				return true;
			}
			++right;
			++tempnum[s2[right] - 'a'];
			//increase a valid char number matching;
			if (tempnum[s2[right] - 'a'] == char2num[s2[right] - 'a']) {
				++count;
			}
			//decrease a valid char number matching;
			else if (tempnum[s2[right] - 'a'] == char2num[s2[right] - 'a'] + 1) {
				--count;
			}
			++left;
			--tempnum[s2[left-1] - 'a'];
			//increase a valid char number matching;
			if (tempnum[s2[left-1] - 'a'] == char2num[s2[left-1] - 'a']) {
				++count;
			}
			//decrease a valid char number matching;
			else if (tempnum[s2[left-1] - 'a'] == char2num[s2[left-1] - 'a'] - 1) {
				--count;
			}
		}
		//previsou cmpararison missed the case of right=s2.size()-1;
		return count==26;
	}
};

int main() {
	string s1 = "ab";
	string s2 = "eidboaoo";
	std::cout << Solution().checkInclusion(s1, s2);
	cin.get();
	return 0;
}