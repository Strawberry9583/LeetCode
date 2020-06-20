#include<vector>
#include<string>
#include<iostream>
#include<stack>

using namespace std;

// solution1: record the last result;
// if current price >= result then compare from the last m_pre.end()-1-result;
class StockSpanner1 {
private:
	std::vector<int> m_pre;
	int m_pre_result;
public:
	StockSpanner1() {

	}

	int next(int price) {
		if (m_pre.empty()) {
			m_pre.emplace_back(price);
			m_pre_result=1;
			return 1;
		}
		//int result = 1;
		if (price >= m_pre.back()) {
			for (int idx = m_pre.size()-1- m_pre_result; idx >= 0; --idx) {
				if (m_pre[idx] <= price) {
					++m_pre_result;
				}
				else {
					break;
				}
			}
			++m_pre_result;
		}
		else {
			m_pre_result = 1;
			for (int idx = m_pre.size() - 1; idx >= 0; --idx) {
				if (m_pre[idx] <= price) {
					++m_pre_result;
				}
				else {
					break;
				}
			}
		}
		m_pre.emplace_back(price);
		return m_pre_result;
	}
};

//// solution2: record all the result;
// find the first number to be greater than the current one;
class StockSpanner {
private:
	std::vector<int> m_pre;
	std::vector<int> m_result;
public:
	StockSpanner() {
		ios::sync_with_stdio(false); cin.tie(0);
	}

	int next(int price) {
		if (m_pre.empty()) {
			m_pre.emplace_back(price);
			m_result.emplace_back(1);
			return 1;
		}
		int result = 1;
		int left_idx = m_pre.size() - 1;
		while (left_idx >= 0&& m_pre[left_idx] <= price) {
			left_idx -= m_result[left_idx];
		}
		if (left_idx < 0) {
			result += m_pre.size();
		}
		else {
			result += m_pre.size() - (left_idx+1);
		}
		m_result.emplace_back(result);
		m_pre.emplace_back(price);
		return result;
	}
};

// solution 3: similar method as solution2; 
// but actually the prices < top can be erased;
class StockSpanner3 {
	stack<int> prices;
	stack<int> weights;
public:
	StockSpanner3() {
	}

	int next(int price) {
		int w = 1;
		while (!prices.empty() && prices.top() <= price) {
			prices.pop();
			w += weights.top();
			weights.pop();
		}

		prices.push(price);
		weights.push(w);
		return w;
	}
};

int main() {
	StockSpanner3 sol;
	std::cout << sol.next(100);
	std::cout << sol.next(80);
	std::cout << sol.next(60);
	std::cout << sol.next(70);
	std::cout << sol.next(60);
	std::cout << sol.next(75);
	cin.get();
	return 0;
}