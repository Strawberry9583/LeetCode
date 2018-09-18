#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int min(const int x, const int y) {
		return x < y ? x : y;
	}

	int maxArea(vector<int> & height)
	{
		int max_i;
		int max_j;
		int max_volume=0;
		for (int i = 0, j = height.size() - 1; i!=j; )
		{
			int temp = (j - i)*min(height[j], height[i]);
			if (temp > max_volume)
			{
				max_i = i;
				max_j = j;
				max_volume = temp;
			}
			if (height[i] < height[j])
			{
				++i;
			}
			else
			{
				--j;
			}
			//	for (int j = i+1; j < height.size(); ++j)
			//	{
			//		if (min(height[i], height[j])*(j - i) > max_volume)
			//		{
			//			max_volume = min(height[i], height[j])*(j - i);
			//			max_i = i;
			//			max_j = j;
			//		}
			//	}
			//}
		}
		return max_volume;
	}
};


int main()
{
	Solution sol;
	vector<int> height = { 1,8,6,2,5,4,8,3,7 };
	sol.maxArea(height);
	cout << "Max area is " << sol.maxArea(height) << endl;
	cin.get();
	return 0;

}