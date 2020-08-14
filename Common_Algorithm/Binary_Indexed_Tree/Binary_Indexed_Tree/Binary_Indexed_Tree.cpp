// binary indexed tree to accelarate the calculation of interval sum;
// besides, BIT supports the value updating.
// update time complexity: O(lgn);
// sum time complexity: O(lgn)
// ref: https://mp.weixin.qq.com/s/XKbKl87fN5idaqyGeQr2DQ

#include<iostream>
#include<vector>

using namespace std;

class binary_indexed_tree {
private:
	std::vector<int> m_BITree;
	int m_mode = 1000000009;
public:
	// size is the arr.length+1, which includes a root;
	binary_indexed_tree(int size) :m_BITree(size,0) {
		
	}
	int getSum(int index) {
		int sum = 0;
		//the first pos stores a zero;
		index = index + 1;
		while (index>0) {
			sum += m_BITree[index];
			index -= index&(-index);
		}
		return sum;
	}

	void updateTree(int n, int index, int val) {
		//the first pos stores a zero;
		index = index + 1;
		while (index<=n) {
			m_BITree[index] += val;
			index += index&(-index);
		}
	}

};


int main() {
	std::vector<int> test_vec{ 2,1,1};
	binary_indexed_tree tree(4);
	for (int idx = 0; idx < test_vec.size(); ++idx) {
		tree.updateTree(test_vec.size(), idx, test_vec[idx]);
	}
	std::cout << tree.getSum(3);

	cin.get();
	return 0;
}