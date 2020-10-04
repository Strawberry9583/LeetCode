#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_set>
#include<unordered_map>

using namespace std;
class ParkingSystem {
	std::vector<int> type2num;
public:
	ParkingSystem(int big, int medium, int small) {
		type2num.resize(3, 0);
		type2num[0] = big;
		type2num[1] = medium;
		type2num[2] = small;

	}

	bool addCar(int carType) {
		if (type2num[carType - 1] > 0) {
			--type2num[carType - 1];
			return true;
		}
		else {
			return false;
		}
	}
};



//class Solution {
//public:
//	vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
//		std::unordered_map<string, std::vector<int>> name2hourfreq;
//		std::unordered_set<string> result;
//		for (int idx = 0; idx < keyName.size(); ++idx) {
//			int charidx = keyTime[idx].find(':');
//			string hour_s = keyTime[idx].substr(0, charidx);
//			string minite_s = keyTime[idx].substr(charidx + 1, keyTime[idx].size() - charidx);
//			int hour = std::stoi(hour_s), minite = std::stoi(minite_s);
//			if (name2hourfreq.find(keyName[idx]) == name2hourfreq.end()) {
//				name2hourfreq[keyName[idx]].resize(24,0);
//			}
//			if (minite == 0) {
//				++name2hourfreq[keyName[idx]][hour];
//				if (name2hourfreq[keyName[idx]][hour] > 2) {
//					result.emplace(keyName[idx]);
//				}
//				if (hour == 0) {
//					++name2hourfreq[keyName[idx]][23];
//					if (name2hourfreq[keyName[idx]][23] > 2) {
//						result.emplace(keyName[idx]);
//					}
//				}
//				else {
//					++name2hourfreq[keyName[idx]][hour - 1];
//					if (name2hourfreq[keyName[idx]][hour - 1] > 2) {
//						result.emplace(keyName[idx]);
//					}
//				}
//			}
//			else {
//				++name2hourfreq[keyName[idx]][hour];
//				if (name2hourfreq[keyName[idx]][hour] > 2) {
//					result.emplace(keyName[idx]);
//				}
//			}
//		}
//		std::vector<string> ans;
//		for (const auto & ele : result) {
//			ans.emplace_back(ele);
//		}
//		std::sort(ans.begin(), ans.end());
//		return ans;
//	}
//};


int main() {
	//std::vector<string> keyname{ "leslie","leslie","leslie","clare","clare","clare","clare" };
	//std::vector<string> keyTime{ "13:00","13:20","14:00","18:00","18:51","19:30","19:49" };
	//auto ans = Solution().alertNames(keyname, keyTime);
	//for (auto & ele : ans) {
	//	std::cout << ele << "  ";
	//}
	cin.get();
	return 0;
}