#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		std::unordered_map<char, int> magazine_count;
		for (auto & ele : magazine) {
			++magazine_count[ele];
		}
		for (auto & ele : ransomNote) {
			--magazine_count[ele];
			if (magazine_count[ele] < 0) {
				return false;
			}
		}
		return true;
	}
};

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		//Sets whether the standard C++ streams are synchronized to 
		// the standard C streams after each input/output operation.
		std::ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		vector<int> v(26, 0);
		for (char i : magazine)
			++v[i - 'a'];
		for (char j : ransomNote)
			if (--v[j - 'a']<0) return false;
		return true;

	}
};

int main() {


	std::cin.get();
	return 0;
}