#include<iostream>
#include<vector>
#include<math.h>


using namespace std;

class Solution 
{
public:
	double findMedianSortedArrays(vector <int>& nums1, vector<int>& nums2) 
	{
		size_t size_1 = nums1.size();
		size_t size_2 = nums2.size();
		size_t size_all = size_1 + size_2;
		size_t index = -1;
		size_t index_end = (size_1 + size_2 - 1) / 2;
		auto m_iter = nums1.begin();
		auto n_iter = nums2.begin();
		auto m_end_iter = nums1.end();
		auto n_end_iter = nums2.end();
		size_t all = 0;
		vector<int> temp_vec;
		auto temp_iter = temp_vec.end();
		while ((n_iter!=n_end_iter)&&(m_iter!=m_end_iter)&&(index!=index_end))
		{
			if ((*m_iter) > (*n_iter))
			{
				temp_vec.insert(temp_iter, *n_iter);
				++n_iter;
			}
			else
			{
				temp_vec.insert(temp_iter, *m_iter);
				++m_iter;
				
			}
			temp_iter = temp_vec.end();
			++index;
		}
		while ((n_iter != n_end_iter)&&((index != index_end)))
		{
			temp_vec.insert(temp_iter, *n_iter);
			temp_iter = temp_vec.end();
			++n_iter;
			++index;
		}
		while ((m_iter!=m_end_iter)&&(index != index_end))
		{
			temp_vec.insert(temp_iter, *m_iter);
			temp_iter = temp_vec.end();
			++m_iter;
			++index;
		}
		double result;
		//caution the Priority of the == and &;
		if ((size_all& 1 )== 1)
		{
			//result = temp_vec[(temp_vec.size()-1) / 2];
			result = temp_vec[temp_vec.size() - 1];
		}
		else
		{
			//result = (double(temp_vec[temp_vec.size() / 2])) + (double(temp_vec[(temp_vec.size() - 1) / 2]));
			//result /= 2.0;
			result = temp_vec[temp_vec.size() - 1];
			if (m_iter == m_end_iter)
			{
				result += (*n_iter);
				result /= 2.0;
			}
			else if (n_iter == n_end_iter)
			{
				result += (*m_iter);
				result /= 2.0;
			}
			else
			{
				result += fmin(*m_iter, *n_iter);
				result /= 2.0;
			}

		}
		//cout << result;
		return result;
	}
};

int main()
{
	Solution so;
	vector<int> nu1 = { 1,3 };
	vector<int> nu2 = { 2 };
	so.findMedianSortedArrays(nu1, nu2);

	return 0;
}