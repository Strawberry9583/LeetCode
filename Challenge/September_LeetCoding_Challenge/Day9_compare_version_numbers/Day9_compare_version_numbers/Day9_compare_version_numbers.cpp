#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		std::vector<int> vec_1, vec_2;
		stringstream ss(version1);
		string temp;
		while (std::getline(ss,temp,'.')) {
			int temp_i = std::stoi(temp);
			vec_1.emplace_back(std::move(temp_i));
		}
		stringstream ss1(version2);
		while (std::getline(ss1,temp,'.')) {
			int temp_i = std::stoi(temp);
			vec_2.emplace_back(std::move(temp_i));
		}
		while (vec_1.size()<4) {
			vec_1.emplace_back(0);
		}
		while (vec_2.size()<4) {
			vec_2.emplace_back(0);
		}
		for (int idx = 0; idx < 4; ++idx) {
			if (vec_1[idx] < vec_2[idx]) {
				return -1;
			}
			else if(vec_1[idx]>vec_2[idx]) {
				return 1;
			}
		}
		return 0;
	}
};

int main() {
	string version1 = "0.1", version2 = "1.1";
	std::cout << Solution().compareVersion(version1, version2);
	cin.get();
	return 0;
}