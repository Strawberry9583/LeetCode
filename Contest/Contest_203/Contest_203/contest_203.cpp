#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<functional>
#include<set>
#include<map>

using namespace std;


class Solution1 {
public:
	vector<int> mostVisited(int n, vector<int>& rounds) {
		/*if (rounds.size() == 1) {
			return
		}
*/
		std::vector<int> visit_freq(n + 1, 0);
		for (int round_idx = 0; round_idx + 1 < rounds.size(); ++round_idx) {
			for (int start = rounds[round_idx]; start != rounds[round_idx + 1];) {
				++visit_freq[start];
				++start;
				if (start > n) {
					start = 1;
				}
			}
		}
		++visit_freq[rounds.back()];
		std::vector < std::pair<int, int>> freqAndIdx;
		for (int idx = 1; idx < visit_freq.size(); ++idx) {
			freqAndIdx.emplace_back(visit_freq[idx], idx);
		}
		std::sort(freqAndIdx.begin(), freqAndIdx.end(), [](const std::pair<int, int>& rhs1,
			const std::pair<int, int>& rhs2) {
			return rhs1.first != rhs2.first ? rhs1.first > rhs2.first:rhs1.second < rhs2.second;
		});
		std::vector<int> result;
		result.emplace_back(freqAndIdx.front().second);
		for (int idx = 1; idx < freqAndIdx.size(); ++idx) {
			if (freqAndIdx[idx].first < freqAndIdx[idx - 1].first) {
				break;
			}
			else {
				result.emplace_back(freqAndIdx[idx].second);
			}
		}
		return result;
	}
};

class Solution2 {
public:
	int maxCoins(vector<int>& piles) {
		std::sort(piles.begin(), piles.end(), [](const int rhs1, const int rhs2) {
			return rhs1 > rhs2;
		});
		int num_pick = piles.size() / 3;
		int result = 0;
		for (int idx = 0; idx < num_pick; ++idx) {
			result += piles[2 * idx + 1];
		}
		return result;
	}
};

// binary search + backward check;
// record the pos of zero from the back to the front, then the substring of '1' will be the known that
// all the substring of '1' is divided by the zero;
// eg: zero pos is i, then check the first zero smaller then i and first zero bigger than i;
// the new generated substring '1' will be the sub[pos_less,i-1] and sub[i+1,pos_bigger];
// Time complexity: O(n*lgn); Space complexity: O(n);
class Solution3_1 {
public:
	int findLatestStep(vector<int>& arr, int m) {
		if (arr.size() == m) {
			return m;
		}
		std::vector<int> zero_pos{ 0,(int)arr.size() + 1 };
		int result = -1;
		for (int step = arr.size(); step > 0; --step) {
			// binary search to find the first pos bigger then arr[step-1];
			auto first_greater = upper_bound(arr.begin(),arr.end(),arr[step - 1]);
			// check whether the two sizes of new generated '1' substring is equal to m;
			if (((*first_greater) - arr[step - 1]-1 == m) || (arr[step - 1] - (*(first_greater - 1))-1 == m)) {
				result=step - 1;
				break;
			}
			else {
				zero_pos.emplace(first_greater, arr[step - 1]);
			}
		}
		return result;
	}
};

// Union-find
// regard the problem as a range merge problem;
// when changing the pos to '1', then if the pos-1 or pos+1 is also the '1', then range can be merged;
// besides, the range length can be recorded with count so if the merged size is equal to m; update the step;
class Solution3_2 {
public:
	vector<int> m_parent; // record the m_parent position of current pos;
	vector<int> m_count; // m_count[i] indicates the length of current group;
	vector<int> m_groupCounts;	// m_groupCounts[i] stores numbers of groups of size `i`;
	int Find(int x) {
		return m_parent[x] == x ? x : m_parent[x] = Find(m_parent[x]);
	}
	void Union(int x, int y)			//Modified union to update m_groupCounts
	{
		int xset = Find(x), yset = Find(y);
		if (xset != yset) {
			m_groupCounts[m_count[xset]]--, m_groupCounts[m_count[yset]]--;//Union'ing would change the groupSize of current x and y groups.
			m_count[xset] = m_count[yset] = m_count[xset] + m_count[yset];		//Size of groups of x and y now are now size(x)+size(y)
			m_groupCounts[m_count[xset]]++;
			m_parent[yset] = xset;
		}
	}
	int findLatestStep(vector<int>& arr, int m) {
		m_parent.resize(arr.size() + 1);		//Few lines for basic initialization.
		for (int i = 1; i <= arr.size(); i++)
			m_parent[i] = i;
		vector<bool> visited(arr.size() + 1, false);
		m_count.resize(arr.size() + 1, 1);			//Currently all groups are of size 1
		m_groupCounts.resize(arr.size() + 1, 0);
		int last = -1, step = 1;						//Last stores the result, step is the current step (We can move this to a for loop)
		for (int &i : arr) {
			m_groupCounts[1]++;					//We always chose a new number whose current groupSize is 1 so we increase the groupCount[1] (Reverse Map)
			if (i + 1 <= arr.size() && visited[i + 1])	//Union i and i+1 if i+1'th bit was previously set
				Union(i, i + 1);
			if (i - 1 > 0 && visited[i - 1])				//Union i and i-1 if i-1'th bit was previously set
				Union(i, i - 1);
			visited[i] = true;
			if (m_groupCounts[m])					//If m_counts of group of size m is > 0 (This means we have a group of size m at current step, update `last`)
				last = step;
			step++;
		}
		return last;
	}
};

// Union-find with rank optimization;
// rank means the depth of the nodes and set the parent for the nodes with higher depth;
class Solution3_3 {
public:
	vector<int> parent, Rank, count, groupCounts;	//Basic union find related storages (groupCounts stores # of groups of size `i`- our reverse mapping)
	int Find(int x) {
		return parent[x] == x ? x : parent[x] = Find(parent[x]);
	}
	void Union(int x, int y)			//Modified union to update groupCounts
	{
		int xset = Find(x), yset = Find(y);
		if (xset != yset) {
			groupCounts[count[xset]]--, groupCounts[count[yset]]--;//Union'ing would change the groupSize of current x and y groups.
			count[xset] = count[yset] = count[xset] + count[yset];		//Size of groups of x and y now are now size(x)+size(y)
			groupCounts[count[xset]]++;
			Rank[xset] < Rank[yset] ? parent[xset] = yset : parent[yset] = xset;
			if (Rank[xset] == Rank[yset])
				Rank[xset]++;
		}
	}
	int findLatestStep(vector<int>& arr, int m) {
		parent.resize(arr.size() + 1), Rank.resize(arr.size() + 1, 0);			//Few lines for basic initialization.
		for (int i = 1; i <= arr.size(); i++)
			parent[i] = i;
		vector<bool> visited(arr.size() + 1, false);
		count.resize(arr.size() + 1, 1);			//Currently all groups are of size 1
		groupCounts.resize(arr.size() + 1, 0);
		int last = -1, step = 1;						//Last stores the result, step is the current step (We can move this to a for loop)
		for (int &i : arr) {
			groupCounts[1]++;					//We always chose a new number whose current groupSize is 1 so we increase the groupCount[1] (Reverse Map)
			if (i + 1 <= arr.size() && visited[i + 1])	//Union i and i+1 if i+1'th bit was previously set
				Union(i, i + 1);
			if (i - 1 > 0 && visited[i - 1])				//Union i and i-1 if i-1'th bit was previously set
				Union(i, i - 1);
			visited[i] = true;
			if (groupCounts[m])					//If counts of group of size m is > 0 (This means we have a group of size m at current step, update `last`)
				last = step;
			step++;
		}
		return last;
	}
};
int main() {
	//std::vector<int>test_vec{ 2,1,2,1,2,1,2,1,2 };
	//int n = 2;
	//auto ans = Solution1().mostVisited(n, test_vec);
	//for (auto ele : ans) {
	//	std::cout << ele << " ";
	//}

	//std::vector<int>test_vec{ 9,8,7,6,5,1,2,3,4 };
	//std::cout << Solution2().maxCoins(test_vec);

	std::vector<int> test_vec{ 3,5,1,2,4 };
	int m = 1;
	std::cout << Solution().findLatestStep(test_vec, m);

	cin.get();
	return 0;
}