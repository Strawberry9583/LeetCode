#include<iostream>
#include<vector>

using namespace std;

// Give candy to everyone each "turn" first [until you can't], 
// then give candy to one person per turn.
class Solution {
public:
	vector<int> distributeCandies(int candies, int num_people) {
		std::vector<int> result(num_people, 0);
		int turn = 1;
		while (1) {
			int turn_need = num_people * (num_people + 1) / 2;
			turn_need += num_people * (turn - 1)*num_people;
			if (turn_need > candies) {
				break;
			}
			else {
				++turn;
				candies -= turn_need;
			}
		}
		for (int idx = 0; idx < num_people; ++idx) {
			if (candies >= (turn - 1)*num_people + idx + 1) {
				result[idx] = (idx + 1)*turn + ((turn - 1)*(turn)*num_people / 2);
				candies -= (turn - 1)*num_people + idx + 1;
			}
			else {
				result[idx] = (idx + 1)*(turn - 1) + ((turn - 2)*(turn - 1)*num_people / 2) + candies;
				candies = 0;
			}
		}
		return result;
	}
};

int main() {
	cin.get();
	return 0;
}