#include <iostream>
#include <cassert>
#include <vector>
#include <memory>
using namespace std;

struct Cycle {
	int length;
};

struct Node {
	int distToCycle;
	shared_ptr<Cycle> cycle;
	int cycleIndex;
	Node* next;
	Node() : distToCycle(-1), next(0) {}
};

void dfs(Node* node) {
	if (node->distToCycle >= 0)
		return;
	if (node->distToCycle == -2) {
		shared_ptr<Cycle> cycle(new Cycle());
		Node* p = node;
		int index = 0;
		do {
			p->distToCycle = 0;
			p->cycle = cycle;
			p->cycleIndex = index++;
			p = p->next;
		} while (p != node);
		cycle->length = index;
		return;
	}
	node->distToCycle = -2;
	dfs(node->next);
	if (node->distToCycle == -2) {
		node->distToCycle = node->next->distToCycle + 1;
		node->cycle = node->next->cycle;
		node->cycleIndex = node->next->cycleIndex;
	}
}

int dist(Node* a, Node* b) {
	assert(a->cycle == b->cycle);
	if (b->distToCycle > 0) {
		return a->distToCycle - b->distToCycle;
	}
	int dist = a->distToCycle, cd = (b->cycleIndex - a->cycleIndex);
	if (cd >= 0)
		return dist + cd;
	else
		return dist + cd + a->cycle->length;
}

int main() {
	int N;
	cin >> N;
	vector<Node> nodes(N);
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		nodes[i].next = &nodes[a - 1];
	}
	for (int i = 0; i < N; ++i)
		dfs(&nodes[i]);
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		cout << dist(&nodes[a], &nodes[b]) << endl;
	}
	return 0;
}
