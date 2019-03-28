#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

//class Solution {
//public:
//	struct data
//	{
//		int m_value;
//		//m_idx to record the element having been selected;
//		//which can avoid the repeated element in the composition;
//		int m_idx;
//	};
//	vector<vector<int>> threeSum(vector<int>& nums) {
//		// key is the sum of the two in the pair;
//		multimap<int, pair<data, data> >  two_sum;
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			for (int j = i + 1; j < nums.size(); ++j)
//			{
//				data data1, data2;
//				data1.m_value = nums[i];
//				data1.m_idx = i;
//				data2.m_value = nums[j];
//				data2.m_idx = j;
//
//				two_sum.insert(pair<int,
//					pair<data,data>>(nums[i]+nums[j],pair<data,data>(data1,data2)));
//			}
//		}
//		vector<vector<int>> result;
//		set<vector<int>> temp_set;
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			int target = -nums[i];
//			auto find = two_sum.find(target);
//			//未重复利用元素；
//			while (find!=two_sum.end())
//			{
//				if ((*find).second.first.m_idx != i && (*find).second.second.m_idx != i)
//				{
//					vector<int> temp = { (*find).second.first.m_idx,(*find).second.second.m_idx,i };
//					sort(temp.begin(), temp.end(), [](const int i1, const int i2) {return i1 < i2; });
//					temp_set.insert(temp);
//				}
//				two_sum.erase(find);
//				find = two_sum.find(target);
//			}
//
//		}
//		for (auto i = temp_set.begin(); i != temp_set.end(); ++i)
//		{
//			vector<int>  temp_vec;
//			for (auto j = (*i).begin(); j != (*i).end(); ++j)
//			{
//				temp_vec.push_back(nums[*j]);
//			}
//			result.push_back(temp_vec);
//		}
//		temp_set.clear();
//		for (auto i = result.begin(); i != result.end(); ++i)
//		{
//			sort((*i).begin(), (*i).end(), [](const int i1, const int i2) {return i1 < i2; });
//			temp_set.insert(*i);
//		}
//
//		result.clear();
//		for (auto i = temp_set.begin(); i != temp_set.end(); ++i)
//		{
//			result.push_back(*i);
//		}
//		return result;
//	}
//};


class Solution {
public:

	struct data
	{
		int m_value;
		//m_idx to record the element having been selected;
		//which can avoid the repeated element in the composition;
		int m_idx;
	};

	//vector<vector<int>> threeSum(vector<int>& nums) {
	//	vector<vector<int> > result;
	//	set<vector<int> > s_result;


	vector< vector<int> > threeSum(vector<int> &num) {
		vector<int> numSet(3);
		vector< vector<int> > r;
		// 1.排序
		sort(num.begin(), num.end());
		int sum;
		int len = num.size();
		// 2.拿出第一个数，转化为两数和问题。注意外层循环到倒数第三个数即可
		for (int i = 0; i < len - 2; i++) {
			sum = 0 - num[i];
			numSet[0] = num[i];
			// 3.两数和问题
			for (int j = i + 1, k = len - 1; j < k;) {
				if (num[j] + num[k] == sum) {
					numSet[1] = num[j++];
					numSet[2] = num[k--];
					r.push_back(numSet);
					// 根据题目要求，跳过重复元素
					while (j < k && num[j] == num[j - 1])
						j++;
					while (j < k && num[k] == num[k + 1])
						k--;
				}
				else if (num[j] + num[k] < sum)
					j++;
				else
					k--;
			}
			while (i < len - 2 && num[i + 1] == num[i])
				i++;
		}
		return r;
	}

	//	sort(nums.begin(), nums.end(), [](const int i1, const int i2) {return i1 < i2; });


	//	for (auto i = nums.begin(); i != nums.end()-2; )
	//	{
	//		int target = -1 * (*i);
	//		auto slow = i+1, fast = nums.end()-1;

	//		while (slow<fast)
	//		{
	//			if ((*slow) + (*fast) == target)
	//			{
	//				vector<int> temp_vec;
	//				temp_vec.push_back(*slow);
	//				temp_vec.push_back(*fast);
	//				temp_vec.push_back(*i);
	//				sort(temp_vec.begin(), temp_vec.end(), [](const int i1, const int i2) {return i1 < i2; });
	//				s_result.insert(temp_vec);
	//				++slow;
	//				//--fast;
	//				//while (slow < fast && (*slow) == *(slow + 1))
	//				//	++slow;
	//				//while (slow < fast && (*fast) == *(fast-1))
	//				//	--fast;
	//			}
	//			else if ((*slow) + (*fast) > target)
	//			{
	//				--fast;
	//				while ((*fast)==(*(fast+1)))
	//				{
	//					--fast;
	//				}
	//			}
	//			else
	//			{
	//				++slow;
	//				while ((*slow)==(*(slow-1)))
	//				{
	//					++slow;
	//				}
	//			}
	//			++i;
	//		}
	//		//while (i!=nums.end()&&(*i)==(*(i+1)))
	//		//{
	//		//	++i;
	//		//}
	//		while (i<nums.end()-2&&(*i)==(*(i-1)))
	//		{
	//			++i;
	//		}
	//	}
	//	for (auto  i : s_result)
	//	{
	//		result.push_back(i);
	//	}
	//	return result;
	//}
};

int main()
{
	Solution sol;
	vector<int> input = { -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	//vector<int> input = { 0,0,0,0};

	vector<vector<int>> result = sol.threeSum(input);
	for (auto & i : result)
	{
		for (auto & j : i)
		{
			cout << j << "  ";
		}
		cout << endl;
	}
	cin.get();
	return 0;
}