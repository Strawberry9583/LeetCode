#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<unordered_set>

using namespace std;

// solution1: store the intermediate states and chech whether to be repeated;
struct state {
public:
	int m_x;
	int m_y;
	int m_ins_idx;
	char m_dir;
public:
	state(int x, int y, int ins_idx,char dir) :m_x(x), m_y(y), m_ins_idx(ins_idx),m_dir(dir) {}

};
bool operator ==(const state& rhs1, const state & rhs2) {
	return rhs1.m_x == rhs2.m_x&&rhs1.m_y == rhs2.m_y&&rhs1.m_ins_idx == rhs1.m_ins_idx&&rhs1.m_dir==rhs2.m_dir;
}
struct state_hash {
	size_t operator()(const state& s)const {
		return hash<int>()(s.m_x) + hash<int>()(s.m_y) + hash<int>()(s.m_ins_idx)+hash<char>()(s.m_dir);
	}
};


class Solution1 {

public:
	bool isRobotBounded(string instructions) {
		int step = instructions.size()*instructions.size();
		step = step * 4;
		step += 1;
		int cur_x =0, cur_y = 0;
		char cur_dir = 'N';
		std::unordered_set<state,state_hash> previous_state;
		//std::unordered_set<state,
		for (int step_idx = 0; step_idx < step; ++step_idx) {
			int ins_idx = step_idx % instructions.size();
			char ins = instructions[ins_idx];
			std::cout << cur_x << " " << cur_y << " " << ins_idx << " " << cur_dir << std::endl;
			if (previous_state.find(state(cur_x, cur_y, ins_idx,cur_dir))==previous_state.end()) {
				previous_state.emplace(cur_x, cur_y, ins_idx, cur_dir);
			}
			
			else {
				return true;
			}
			if (ins == 'G') {
				if (cur_dir == 'N') {
					++cur_y;
				}
				else if (cur_dir == 'S') {
					--cur_y;
				}
				else if (cur_dir == 'W') {
					--cur_x;
				}
				else if (cur_dir == 'E') {
					++cur_x;
				}
			}
			else if (ins == 'L') {
				if (cur_dir == 'N') {
					cur_dir = 'W';
					//--cur_x;
				}
				else if (cur_dir == 'S') {
					cur_dir = 'E';
					//++cur_x;
				}
				else if (cur_dir == 'W') {
					cur_dir = 'S';
					//--cur_y;
				}
				else if (cur_dir == 'E') {
					cur_dir = 'N';
					//++cur_y;
				}
			}
			else if (ins == 'R') {
				if (cur_dir == 'N') {
					cur_dir = 'E';
					//++cur_x;
				}
				else if (cur_dir == 'S') {
					cur_dir = 'W';
					//--cur_x;
				}
				else if (cur_dir == 'W') {
					cur_dir = 'N';
					//++cur_y;
				}
				else if (cur_dir == 'E') {
					cur_dir = 'S';
					//--cur_y;
				}
			}
		}
		return false;
	}
};

//solution 2:
//
//Starting at the origin and face north(0, 1),
//after one sequence of instructions,
//
//if chopper return to the origin, he is obvious in an circle.
//if chopper finishes with face not towards north,
//it will get back to the initial status in another one or three sequences.

class Solution {
public:
	bool isRobotBounded(string instructions) {
		int x = 0, y = 0, i = 0;
		vector<vector<int>> d = { {0, 1}, {1, 0}, {0, -1}, { -1, 0} };
		for (char & ins : instructions)
			if (ins == 'R')
				i = (i + 1) % 4;
			else if (ins == 'L')
				i = (i + 3) % 4;
			else
				x += d[i][0], y += d[i][1];
		return x == 0 && y == 0 || i > 0;
	}
};

int main() {
	string instruction = "GL";
	std::cout << Solution().isRobotBounded(instruction);
	cin.get();
	return 0;
}