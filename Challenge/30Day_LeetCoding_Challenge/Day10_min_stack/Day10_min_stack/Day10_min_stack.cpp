#include<deque>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

//solution 1:
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		if (m_min.empty() || x < m_min.top()) {
			m_min.push(x);
		}
		else if (x >= m_min.top()) {
			m_min.push(m_min.top());
		}
		m_num.push(x);
	}

	void pop() {
		m_num.pop();
		m_min.pop();
	}

	int top() {
		return m_num.top();
	}

	int getMin() {
		return m_min.top();
	}
private:
	std::stack<int> m_num;
	std::stack<int> m_min;

};

//solution 2:
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		if (m_min.empty() || x <= m_min.top()) {
			m_min.push(x);
		}
		m_num.push(x);
	}

	void pop() {
		if (m_num.top() == m_min.top()) {
			m_min.pop();
		}
		m_num.pop();
	}

	int top() {
		return m_num.top();
	}

	int getMin() {
		return m_min.top();
	}
private:
	std::stack<int> m_num;
	std::stack<int> m_min;

};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/