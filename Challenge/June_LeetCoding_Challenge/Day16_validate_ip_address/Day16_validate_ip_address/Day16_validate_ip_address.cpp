#include<iostream>
#include<string>
#include<vector>
#include<regex>
#include<sstream>

using namespace std;

// solution1: extract the segment from the string then judge the validity;
class Solution1 {
public:
	string validIPAddress(string IP) {
		if (valideIPV4(IP)) {
			return string("IPv4");
		}
		else if (valideIPV6(IP)) {
			return string("IPv6");
		}
		else {
			return string("Neither");
		}
	}
	bool valideIPV6(string ip) {
		int pre_idx = 0;
		int cur_idx = 0;
		std::vector<string> four_seg;
		for (; cur_idx < ip.size(); ++cur_idx) {
			if (ip[cur_idx] == ':') {
				four_seg.emplace_back(ip.substr(pre_idx, cur_idx - pre_idx));
				pre_idx = cur_idx + 1;
			}
		}
		four_seg.emplace_back(ip.substr(pre_idx, cur_idx - pre_idx));
		if (four_seg.size() != 8) {
			return false;
		}
		for (auto &seg : four_seg) {
			int digit_num = 0;
			for (auto &ele : seg) {
				if ((ele >= '0'&&ele <= '9') || (ele >= 'a'&&ele <= 'f') || (ele >= 'A'&&ele <= 'F')) {
					++digit_num;
				}
				else {
					return false;
				}
			}
			if (digit_num < 5 && digit_num>0) {
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	}
	bool valideIPV4(string ip) {
		int pre_idx = 0;
		int cur_idx = 0;
		std::vector<string> four_seg;
		for (; cur_idx < ip.size(); ++cur_idx) {
			if (ip[cur_idx] == '.') {
				four_seg.emplace_back(ip.substr(pre_idx, cur_idx - pre_idx));
				pre_idx = cur_idx + 1;
			}
		}
		four_seg.emplace_back(ip.substr(pre_idx, cur_idx - pre_idx));
		std::vector<int> four_num;
		for (auto & seg : four_seg) {
			if (!seg.empty()) {
				if (seg[0] == '0'&&seg.size() == 1) {
					four_num.emplace_back(0);
				}
				else if (seg[0] != '0') {
					if (seg.size() == 1) {
						if (seg[0] >= '0'&&seg[0] <= '2') {
							four_num.emplace_back(std::atoi(seg.c_str()));
						}
						else {
							return false;
						}
					}
					else if (seg.size() == 2) {
						if (seg[0] >= '0'&&seg[0] <= '2'&&seg[1] >= '0'&&seg[1] <= '9') {
							four_num.emplace_back(std::atoi(seg.c_str()));
						}
						else {
							return false;
						}
					}
					else if (seg.size() == 3) {
						if (seg[0] >= '0'&&seg[0] <= '2'&&seg[1] >= '0'&&seg[1] <= '9'&&seg[2] >= '0'&&seg[2] <= '5') {
							four_num.emplace_back(std::atoi(seg.c_str()));
						}
						else {
							return false;
						}
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		return four_num.size() == 4;
	}
};

// solution2: use istringstream to divide the the string into segment;
class Solution {
public:
	string validIPAddress(string IP) {
		istringstream is(IP);
		string t = "";
		int cnt = 0;
		if (IP.find(':') == string::npos) { // Check IPv4
			while (getline(is, t, '.')) {
				++cnt;
				if (cnt > 4 || t.empty() || (t.size() > 1 && t[0] == '0') || t.size() > 3) return "Neither";
				for (char c : t) {
					if (c < '0' || c > '9') return "Neither";
				}
				int val = stoi(t);
				if (val < 0 || val > 255) return "Neither";
			}
			return (cnt == 4 && IP.back() != '.') ? "IPv4" : "Neither";
		}
		else { // Check IPv6
			while (getline(is, t, ':')) {
				++cnt;
				if (cnt > 8 || t.empty() || t.size() > 4) return "Neither";
				for (char c : t) {
					if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F')) return "Neither";
				}
			}
			return (cnt == 8 && IP.back() != ':') ? "IPv6" : "Neither";
		}
	}
};

// solution3: use regex to match the string pattern.
class Solution3 {
public:
	string validIPAddress(string IP) {
		regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
		regex ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}");   // create regex object for regulare expression
		if (regex_match(IP, ipv4)) // match regex expression with given IP string for IPv4
			return "IPv4";
		else if (regex_match(IP, ipv6)) // match regex expression with given IP string for IPv6
			return "IPv6";
		return "Neither"; // Otherwise return "Neither"
	}
};

int main() {
	string test = "1e1.4.5.6";
	std::cout << Solution().validIPAddress(test);
	cin.get();
	return 0;
}