#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

//method1: bfs;
class Solution1 {
public:
	Node* cloneGraph(Node* node) {
		if (node == nullptr) {
			return nullptr;
		}
		std::vector<Node*> val2ptr(101, nullptr);
		std::vector<int> cloneflag(val2ptr.size(), 0);
		std::queue<Node*> bfs_queue;
		bfs_queue.emplace(node);
		while (!bfs_queue.empty()) {
			auto cur = bfs_queue.front(); bfs_queue.pop();
			if (cloneflag[cur->val] == 0) {
				if (val2ptr[cur->val] == nullptr) {
					val2ptr[cur->val] = new Node(cur->val);
				}
				for (auto & next : cur->neighbors) {
					if (val2ptr[next->val] == nullptr) {
						val2ptr[next->val] = new Node(next->val);
					}
					if (cloneflag[next->val]==0) {
						bfs_queue.emplace(next);
					}
					val2ptr[cur->val]->neighbors.emplace_back(val2ptr[next->val]);
				}
				cloneflag[cur->val] = 1;
			}
		}
		return val2ptr[node->val];
	}
};


// method2: DFS
class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (!node) {
			return NULL;
		}
		if (copies.find(node) == copies.end()) {
			copies[node] = new Node(node->val, {});
			for (Node* neighbor : node->neighbors) {
				copies[node]->neighbors.push_back(cloneGraph(neighbor));
			}
		}
		return copies[node];
	}
private:
	unordered_map<Node*, Node*> copies;
};


int main() {
	cin.get();
	return 0;
}