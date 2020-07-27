#include<vector>
#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		std::vector<std::vector<int>> result=image;
		std::queue<std::pair<int, int>> pixel_que;
		//if same color with newcolor then there are no operations.
		if (result[sr][sc] != newColor) {
			pixel_que.emplace(std::make_pair(sr, sc));
		}
		int start_color = image[sr][sc];
		while (!pixel_que.empty()) {
			auto pixel = pixel_que.front();
			pixel_que.pop();
			result[pixel.first][pixel.second] = newColor;
			if (pixel.first - 1 >= 0 && start_color == result[pixel.first - 1][pixel.second]) {
				pixel_que.emplace(pixel.first - 1, pixel.second);
			}
			if (pixel.first +1 <result.size() && start_color == result[pixel.first + 1][pixel.second]) {
				pixel_que.emplace(pixel.first + 1, pixel.second);
			}
			if (pixel.second-1  >= 0 && start_color == result[pixel.first][pixel.second-1]) {
				pixel_que.emplace(pixel.first, pixel.second - 1);
			}
			if (pixel.second + 1 <result.front().size() && start_color == result[pixel.first][pixel.second+1]) {
				pixel_que.emplace(pixel.first, pixel.second + 1);
			}
		}
		return result;
	}
};

int main() {
	std::vector<std::vector<int>> test = { {0, 0, 0}, {0, 1, 1} };
	auto ans = Solution().floodFill(test, 1, 1, 1);
	std::cin.get();
	return 0;
}