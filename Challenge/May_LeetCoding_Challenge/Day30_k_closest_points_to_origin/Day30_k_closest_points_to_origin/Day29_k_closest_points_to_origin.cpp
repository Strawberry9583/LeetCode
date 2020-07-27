#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;


// solution1: maximum heap method;
// Time Complexity: O(n*lgK); Space Complexity: O(k);
class Solution1 {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		//cntr maximum heap;
		auto func = [](const pair<long int, int>& rhs1,
			const pair<long int, int>& rhs2) {return rhs1.first < rhs2.first; };
		std::priority_queue<std::pair<long int, int>,std::vector<pair<long int, int>>,decltype(func)>
			que_distance_idx(func);
		for (int idx = 0; idx < points.size(); ++idx) {
			long int dis = points[idx][0] * points[idx][0] + points[idx][1] * points[idx][1];
			if (que_distance_idx.size() < K) {
				que_distance_idx.emplace(dis,idx);
			}
			else {
				if (que_distance_idx.top().first < dis) {
					continue;
				}
				else {
					que_distance_idx.pop();
					que_distance_idx.emplace(dis, idx);
				}
			}
		}
		std::vector<std::vector<int>> result;
		while (!que_distance_idx.empty()) {
			result.emplace_back(points[que_distance_idx.top().second]);
			que_distance_idx.pop();
		}
		return result;
	}
};


// solution 2: sort directly;
// Time Complexity: O(n*lgn); Space Complexity: O(1);
class Solution2 {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		//cntr maximum heap;
		auto func = [](const std::vector<int>& rhs1,
			const std::vector<int>& rhs2) {return rhs1[0]*rhs1[0]+rhs1[1]*rhs1[1]<rhs2[0]*rhs2[0]+rhs2[1]*rhs2[1]; };
		sort(points.begin(), points.end(), func);
		return std::vector<std::vector<int>>(points.begin(), points.begin() + K);
	}
};

// solution 3: call the STL nth_element directly;
class Solution3 {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		auto func = [](const std::vector<int>& rhs1,
			const std::vector<int>& rhs2) {return rhs1[0] * rhs1[0] + rhs1[1] * rhs1[1]<rhs2[0] * rhs2[0] + rhs2[1] * rhs2[1]; };
		nth_element(points.begin(), points.begin() + K - 1, points.end(),func);
		return vector<vector<int>>(points.begin(), points.begin() + K);
	}
};

// solution 4: call the STL partial_sort directly;
class Solution4 {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		auto func = [](const std::vector<int>& rhs1,
			const std::vector<int>& rhs2) {return rhs1[0] * rhs1[0] + rhs1[1] * rhs1[1]<rhs2[0] * rhs2[0] + rhs2[1] * rhs2[1]; };
		partial_sort(points.begin(), points.begin() + K, points.end(), func);
		return vector<vector<int>>(points.begin(), points.begin() + K);
	}
};


// solution5: partition method derived from quick sort;
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		int l = 0, r = points.size() - 1;
		while (true) {
			int p = partition(points, l, r);
			if (p == K - 1) {
				break;
			}
			if (p < K - 1) {
				l = p + 1;
			}
			else {
				r = p - 1;
			}
		}
		return vector<vector<int>>(points.begin(), points.begin() + K);
	}
private:
	bool farther(vector<int>& p, vector<int>& q) {
		return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
	}

	bool closer(vector<int>& p, vector<int>& q) {
		return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
	}

	int partition(vector<vector<int>>& points, int left, int right) {
		int pivot = left, l = left + 1, r = right;
		while (l <= r) {
			if (farther(points[l], points[pivot]) && closer(points[r], points[pivot])) {
				swap(points[l++], points[r--]);
			}
			if (!farther(points[l], points[pivot])) {
				l++;
			}
			if (!closer(points[r], points[pivot])) {
				r--;
			}
		}
		swap(points[pivot], points[r]);
		return r;
	}
};
int main() {
	Solution2  sol;
	std::vector<std::vector<int>> test_vec = {{3, 3}, {5, -1}, {-2, 4}};
	int k = 2;
	auto ans = sol.kClosest(test_vec, k);
	cin.get();
	return 0;
}