#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// solution 1: sort + insertion
// first sort as their height, if with same height, place the people at first, who have
// smaller num of people with heigher scales;
// secondly, insert the people according to  rhw number of people 
// in front of this person who have a height greater than himself/herselt.
// Eg: [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]
// After sorted: [7, 0] [7, 1] [6,1] [5,0] [5,1] [4,4]
// After insertion:
// [7,0]
// [7,0] [7,1]
// [7,0] [6,1] [7,1]
// [5,0] [7,0] [6,1] [7,1]
// [5,0] [5,1] [7,0] [6,1] [7,1]
// [5,0] [5,1] [7,0] [6,1] [4,4] [7,1]
class Solution1 {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		std::sort(people.begin(), people.end(), [](const std::vector<int> &rhs1, const vector<int>&rhs2)
		{return rhs1[0] > rhs2[0] ? rhs1[0] > rhs2[0]:rhs1[1] < rhs2[1]; });
		std::vector<std::vector<int>> result;
		result.reserve(people.size());
		for (int idx = 0; idx < people.size(); ++idx) {
			result.emplace(result.begin() + people[idx][1], people[idx]);
		}
		return result;
	}
};

// solution segementTree to accelerate;
// guidance of the segment-tree: https://blog.csdn.net/johnny901114/article/details/80643017

class SegmentTree {
private:
	int n, N;
	vector<int> segTree;
	int getMid(int l, int h) { return l + (h - l) / 2; }
	int getLeftChild(int i) { return 2 * i + 1; }
	int getRightChild(int i) { return 2 * i + 2; }

	int buildSegTree(int root, int low, int high) {
		if (low>high) return 0;
		if (low == high) return segTree[root] = 1;
		int mid = getMid(low, high);
		return segTree[root] = buildSegTree(getLeftChild(root), low, mid) +
			buildSegTree(getRightChild(root), mid + 1, high);
	}
	int getIdx(int root, int low, int high, int x) {
		if (low == high) return low;
		int left = getLeftChild(root), right = getRightChild(root), mid = getMid(low, high);
		if (x <= segTree[left]) return getIdx(left, low, mid, x);
		return getIdx(right, mid + 1, high, x - segTree[left]);
	}
	void update(int root, int low, int high, int i) {
		if (low == high) {
			segTree[root] = 0;
			return;
		}
		int left = getLeftChild(root), right = getRightChild(root), mid = getMid(low, high);
		if (i <= mid) update(left, low, mid, i);
		else        update(right, mid + 1, high, i);
		segTree[root] = segTree[left] + segTree[right];
		return;
	}
public:
	SegmentTree(int n) {
		this->n = n;
		N = 4 * n + 1;
		segTree = vector<int>(N, 0);
		buildSegTree(0, 0, n - 1);
	}
	int getCorrectSlot(int x) {
		return getIdx(0, 0, n - 1, x);
	}
	void removeSlot(int i) {
		update(0, 0, n - 1, i);
		return;
	}
};

bool comp(const vector<int>&v1, const vector<int>&v2) {
	if (v1[0] == v2[0]) return (v1[1]>v2[1]);
	return (v1[0]<v2[0]);
}

class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

		int i, n = people.size(), pos;
		vector<vector<int>> ret(n);
		sort(people.begin(), people.end(), comp);


		SegmentTree obj(n);
		for (i = 0; i<n; i++) {
			pos = obj.getCorrectSlot(people[i][1] + 1);
			obj.removeSlot(pos);
			ret[pos] = people[i];
		}
		return ret;
	}
};

int main() {
	cin.get();
	return 0;
}