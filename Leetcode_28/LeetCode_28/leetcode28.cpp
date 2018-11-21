//KMP Alg. 

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* compute_prefix_function(char *pattern) {
	int m = strlen(pattern);
	int *next = (int*)malloc(m * sizeof(int));
	next[0] = 0;
	int k = 0;
	int q;

	for (q = 1; q < m; q++) {
		while (k > 0 && (pattern[k] != pattern[q]))
			k = next[k - 1];
		if (pattern[k] == pattern[q])
			k++;
		next[q] = k;
	}
	return next;
}

int KMP_match(char *text, char *pattern) {
	int n = strlen(text);
	int m = strlen(pattern);
	int *next = compute_prefix_function(pattern);
	int q = 0;
	int i;

	for (i = 0; i < n; i++) {
		while (q > 0 && (pattern[q] != text[i]))
			q = next[q - 1];
		if (pattern[q] == text[i])
			q++;
		if (q == m)
			return i + 1 - m;
	}
	free(next);
	return -1;
}


int main() {
	char *s1 = "bababaababababca";
	char *s2 = "ababababca";
	int offset = KMP_match(s1, s2);
	printf("offset is %d\n", offset);
	return 0;
}
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

//class Solution {
//public:
	//BF Alg, time complexity O(m*n);
	//int strStr(string haystack, string needle) {
	//	int result = -1;
	//	if (needle.empty()) {
	//		return 0;
	//	}
	//	for (int i = 0; i <= static_cast<int>(haystack.size()) - static_cast<int>(needle.size()); ++i) {
	//		for (int j = 0; j < needle.size(); ++j) {
	//			if (haystack[i + j] != needle[j]) {
	//				break;
	//			}
	//			else if (haystack[i + j] == needle[j] && j == needle.size() - 1) {
	//				result = i;
	//				return result;
	//			}
	//		}
	//	}
	//	return result;
	//}

	//KMP Alg
	//int strStr(string haystack, string needle) {
	//}
//	
//};
//KMP Alg. is explained. https://leetcode.com/problems/implement-strstr/discuss/12956/C%2B%2B-Brute-Force-and-KMP
//https://blog.csdn.net/v_july_v/article/details/7041827
class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.length(), n = needle.length();
		if (!n) {
			return 0;
		}
		vector<int> lps = kmpProcess(needle);
		for (int i = 0, j = 0; i < m; ) {
			if (haystack[i] == needle[j]) {
				i++;
				j++;
			}
			if (j == n) {
				return i - j;
			}
			if ((i < m) && (haystack[i] != needle[j])) {
				if (j) {
					j = lps[j - 1];
				}
				else {
					i++;
				}
			}
		}
		return -1;
	}
private:
	vector<int> kmpProcess(string& needle) {
		int n = needle.length();
		vector<int> lps(n, 0);
		for (int i = 1, len = 0; i < n; ) {
			if (needle[i] == needle[len]) {
				lps[i++] = ++len;
			}
			else if (len) {
				len = lps[len - 1];
			}
			else {
				lps[i++] = 0;
			}
		}
		return lps;
	}
};

int main() {
	string s1 = "", s2 = "a";
	Solution sol;
	auto ans = sol.strStr(s1, s2);
	cout << ans << endl;


	cin.get();
	return 0;
}