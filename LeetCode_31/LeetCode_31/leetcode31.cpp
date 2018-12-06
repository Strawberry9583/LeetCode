//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order(ie, sorted in ascending order).
//
//The replacement must be in - place and use only constant extra memory.
//
//Here are some examples.Inputs are in the left - hand column and its corresponding outputs are in the right - hand column.
//
//1, 2, 3 → 1, 3, 2
//3, 2, 1 → 1, 2, 3
//1, 1, 5 → 1, 5, 1


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class Solution {
public: 
	//Solution 1:
	//void nextPermutation(vector<int> & nums) {
	//	int back = nums.size() - 1;
	//	while (back>0) {
	//		//the last element is the largest one;
	//		//if true, the back--->the last one exists element larger than nums[back-1];
	//		if (nums[back - 1] < nums[nums.size() - 1]) {
	//			int swap_point = back;
	//			for (int j = back; j < nums.size(); ++j) {
	//				if (nums[back - 1] < nums[j]) {
	//					swap_point = j;
	//					int temp = nums[j];
	//					nums[j]=nums[back - 1];
	//					nums[back - 1] = temp;
	//					break;
	//				}
	//			}
	//			break;
	//		}
	//		//if no elements exists, then keep the vector from back-1 to end() sorted.
	//		else {
	//			for (int j = back - 1; j < nums.size() - 1; ++j) {
	//				if (nums[j] > nums[j + 1]) {
	//					int temp = nums[j];
	//					nums[j] = nums[j + 1];
	//					nums[j + 1] = temp;
	//				}
	//			}
	//			--back;
	//		}
	//	}

	//}
	//Solution 2:
	//Approach 2: Single Pass Approach
	//	Algorithm

	//	First, we observe that for any given sequence that is in descending order, no next larger permutation is possible.For example, no next permutation is possible for the following array :

	//	[9, 5, 4, 3, 1]
	//We need to find the first pair of two successive numbers a[i]a[i] and a[i - 1]a[i−1], from the right, which satisfy a[i] > a[i - 1]a[i]>a[i−1].Now, no rearrangements to the right of a[i - 1]a[i−1] can create a larger permutation since that subarray consists of numbers in descending order.Thus, we need to rearrange the numbers to the right of a[i - 1]a[i−1] including itself.

	//	Now, what kind of rearrangement will produce the next larger number ? We want to create the permutation just larger than the current one.Therefore, we need to replace the number a[i - 1]a[i−1] with the number which is just larger than itself among the numbers lying to its right section, say a[j]a[j].

	//	Next Permutation

	//	We swap the numbers a[i - 1]a[i−1] and a[j]a[j].We now have the correct number at index i - 1i−1.But still the current permutation isn't the permutation that we are looking for. We need the smallest permutation that can be formed by using the numbers only to the right of a[i-1]a[i−1]. Therefore, we need to place those numbers in ascending order to get their smallest permutation.

	//	But, recall that while scanning the numbers from the right, we simply kept decrementing the index until we found the pair a[i]a[i] and a[i - 1]a[i−1] where, a[i] > a[i - 1]a[i]>a[i−1].Thus, all numbers to the right of a[i - 1]a[i−1] were already sorted in descending order.Furthermore, swapping a[i - 1]a[i−1] and a[j]a[j] didn't change that order. Therefore, we simply need to reverse the numbers following a[i-1]a[i−1] to get the next smallest lexicographic permutation.
	void nextPermutation2(vector<int> & num) {
		if (num.empty()) {
			return;
		}

		int len = num.size();

		// Find the index which drop.
		int dropIndex = -1;
		for (int i = len - 1; i >= 0; i--) {
			if (i != len - 1 && num[i] < num[i + 1]) {
				dropIndex = i;
				break;
			}
		}

		// replace the drop index.
		if (dropIndex != -1) {
			for (int i = len - 1; i >= 0; i--) {
				if (num[i] > num[dropIndex]) {
					swap(num, dropIndex, i);
					break;
				}
			}
		}

		// reverse the link.
		int l = dropIndex + 1;
		int r = len - 1;
		while (l < r) {
			swap(num, l, r);
			l++;
			r--;
		}
	}
	void swap(vector<int> & num, int l, int r) {
		int temp = num[l];
		num[l] = num[r];
		num[r] = temp;
	}
};


int main() {
	Solution sol;
	vector<int> test{ 1,2};
	sol.nextPermutation2(test);
	for (auto & i : test) {
		cout << i << ' ';
	}


	cin.get();
	return 0;
}