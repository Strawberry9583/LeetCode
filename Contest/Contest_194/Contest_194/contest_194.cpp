#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;



class Solution {
public:
	vector<string> getFolderNames(vector<string>& names) {
		unordered_map<string, int> count;// A map to store whether the particular name occurs how many times already
		for (auto & name : names) {
			// no existing before, then remain the name and set count as 1;
			if (count.find(name) == count.end()) {
				count[name] = 1;
			}
			// word existed, then find the minimum post-fix idx;
			else {
				string temp_name= name + "(" + std::to_string(count[name]) + ")";
				while (count.find(temp_name)!=count.end()) {
					++count[name];
					temp_name = name + "(" + std::to_string(count[name]) + ")";
				}
				// no existing before, then set count as 1 for new name;
				name = temp_name;
				count[name] = 1;
			}
		}
		return names;
	}
};

int main() {
	std::vector<string> test = { "gta","gta(1)","gta","avalon" };
	Solution().getFolderNames(test);
	cin.get();
	return 0;
}