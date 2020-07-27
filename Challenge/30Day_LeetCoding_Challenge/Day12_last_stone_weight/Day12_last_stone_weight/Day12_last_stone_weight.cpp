#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


//use make_heap function;
class Solution1 {
public:
	int lastStoneWeight(vector<int>& stones) {
		/*std::priority_queue<int> max_heap(stones);*/
		std::make_heap(stones.begin(),stones.end());
		while (stones.size()>1) {
			int max1 = *stones.begin();
			std::pop_heap(stones.begin(), stones.end());
			stones.pop_back();
			int max2 = *stones.begin();
			std::pop_heap(stones.begin(), stones.end());
			stones.pop_back();
			if (max1 != max2) {
				max1 = max1 - max2;
				stones.emplace_back(max1);
				//insert the stone.end()-1 into the heap range of [stones.begin,stones.end-1);
				std::push_heap(stones.begin(), stones.end());
			}
			
		}
		if (stones.empty()) {
			return 0;
		}
		else {
			return *stones.begin();
		}
	}
};

//use priority_queue adaptor to realiaze the max_heap;
class Solution2 {
public:
	int lastStoneWeight(vector<int>& stones) {
		std::priority_queue<int> pri_queue;
		for (auto & ele : stones) {
			pri_queue.push(ele);
		}
		while (pri_queue.size()>1) {
			int max1 = pri_queue.top();
			pri_queue.pop();
			int max2 = pri_queue.top();
			pri_queue.pop();
			if (max1 != max2) {
				pri_queue.push(max1 - max2);
			}
		}

		if (pri_queue.empty()) {
			return 0;
		}
		else {
			return pri_queue.top();
		}
	}
};

int main() {
	Solution2 sol;
	std::cout << sol.lastStoneWeight(std::vector<int>{2, 2});


	std::cin.get();
	return 0;
}