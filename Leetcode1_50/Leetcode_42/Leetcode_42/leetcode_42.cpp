#include<string>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	bool rotateString(string A, string B) {
		if (A.size() != B.size()) {
			return false;
		}
		//if (A == B) {
		//	return true;
		//}
		std::vector<int> all_idx_begin;
		for (int i = 0; i < B.size();) {
			int idx= B.find( A[0],i);
			if ( idx!=std::string::npos) {
				all_idx_begin.emplace_back(idx);
				i = idx + 1;
			}
			else {
				break;
			}
		}
		//string temp = B.substr(5);
		for (auto & begin_idx : all_idx_begin) {
			string temp_str = B.substr(begin_idx);
			temp_str += B.substr(0, begin_idx);
			if (temp_str == A) {
				return true;
			}
		}
		return false;
	}
};

int main() {

	Solution sol;
	sol.rotateString("", "");

	return 0;
}