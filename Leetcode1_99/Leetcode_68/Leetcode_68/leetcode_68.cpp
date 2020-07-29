#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string>result;
		int left = 0, right = 0;
		int length = 0;
		while (right<words.size()) {
			length += words[right].size();
			//if last word then push the last line;
			if (length + right - left <= maxWidth&& right==words.size()-1) {
				result.emplace_back(std::move(merge_line(words, left, right, length, maxWidth)));
				break;
			}
			//if there are rest rooms, then continue push;
			else if (length + right - left <= maxWidth) {
				++right;
			}
			// the room is excessive then push the make a line with range [left,right-1];
			else {
				result.emplace_back(std::move(merge_line(words, left, right - 1, length - words[right].size(), maxWidth)));
				left = right;
				length = 0;
			}
		}
		//adjust the last line to be left-justice;
		auto last_line = result.end() - 1;
		for (int idx = 1; idx < last_line->size();) {
			if ((*last_line)[idx] == ' ' && (*last_line)[idx - 1] == ' ') {
				last_line->erase(last_line->begin() + idx);
			}
			else {
				++idx;
			}
		}
		//the end space may be eliminated by the adjusting of the last line;
		if (last_line->size() < maxWidth) {
			*last_line += string(maxWidth - last_line->size(), ' ');
		}
		return result;
	}
	string merge_line(std::vector<string>& words, int left, int right,int cur_length, int maxWidth) {
		string line;
		if (left == right) {
			line += words[left] + string(maxWidth - words[left].size(), ' ');
		}
		else {
			int rest_length = maxWidth - cur_length;
			int gap = (rest_length) / (right - left);
			//if more_rest ,then allcoate the more rest the left most gaps;
			int more_rest = rest_length - (right - left)*gap;
			if (more_rest == 0) {
				for (int idx = left; idx < right; ++idx) {
					line += words[idx] + string(gap, ' ');					
				}
				line += words[right];
			}
			else {
				for (int idx = left; idx < right; ++idx) {
					//allcoate the one more rest the left most gaps;
					if (idx - left < more_rest) {
						line += words[idx] + string(gap + 1, ' ');
					}
					//allcoate the even space to the right most gaps;
					else {
						line += words[idx] + string(gap, ' ');
					}
				}
				line += words[right];
			}
		}
		return line;
	}
};

int main() {
	Solution sol;
	std::vector<string>test_vec{"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
	int maxWidth = 20;
	std::vector<string> ans = sol.fullJustify(test_vec, maxWidth);
	for (auto line : ans) {
		std::cout << line << std::endl;
	}
	cin.get();
	return 0;
}