#include <vector>
#include <memory>
#include <cstdio>
using namespace std;

struct Cycle {
	int length;
};

struct Node {
	int distToCycle;
	shared_ptr<Cycle> cycle;
	int cycleIndex;
	vector<Node*> children;
	int t0, t1;
	Node* next;
	Node() : distToCycle(-1), next(0) {}
};

int dist(Node* a, Node* b) {
	if (a->cycle != b->cycle)
		return -1;
	if (b->distToCycle > 0) {
		if (!(b->t0 < a->t0 && a->t1 < b->t1))
			return -1;
		return a->distToCycle - b->distToCycle;
	}
	int dist = a->distToCycle, cd = (b->cycleIndex - a->cycleIndex);
	if (cd >= 0)
		return dist + cd;
	else
		return dist + cd + a->cycle->length;
}

void markCycle(Node* start) {
	shared_ptr<Cycle> cycle(new Cycle);
	Node* node = start;
	int ind = 0;
	do {
		node->distToCycle = 0;
		node->cycleIndex = ind++;
		node->cycle = cycle;
		node = node->next;
	} while (node != start);
	cycle->length = ind;
}

void buildTree(vector<Node>& nodes) {
	vector<Node*> stack;
	for (Node& node : nodes) {
		Node* cur = &node;
		if (cur->distToCycle != -1) continue;
		while (cur->distToCycle == -1) {
			cur->distToCycle = -2;
			cur = cur->next;
		}

		if (cur->distToCycle == -2)
			markCycle(cur);

		cur = &node;
		while (cur->distToCycle == -2) {
			stack.push_back(cur);
			cur = cur->next;
		}
		while (!stack.empty()) {
			Node *n1 = stack.back(), *n2 = n1->next;
			n1->cycleIndex = n2->cycleIndex;
			n1->cycle = n2->cycle;
			n1->distToCycle = n2->distToCycle + 1;
			n2->children.push_back(n1);
			stack.pop_back();
		}
	}
}

void visitTree(vector<Node>& nodes) {
	int T = 0;
	enum { PUSH, POP };
	vector<pair<Node*, bool> > stack;
	for (Node& node : nodes) {
		if (node.distToCycle == 0)
			stack.emplace_back(&node, PUSH);
	}
	while (!stack.empty()) {
		Node* node = stack.back().first;
		bool op = stack.back().second;
		stack.pop_back();
		if (op == PUSH) {
			node->t0 = T++;
			stack.emplace_back(node, POP);
			for (Node* ch : node->children)
				stack.emplace_back(ch, PUSH);
		}
		else node->t1 = T++;
	}
}

int main() {
	int N;
	std::ignore = scanf("%d", &N);
	vector<Node> nodes(N);
	for (int i = 0; i < N; ++i) {
		int a;
		std::ignore = scanf("%d", &a);
		nodes[i].next = &nodes[a - 1];
	}
	buildTree(nodes);
	visitTree(nodes);
	int Q;
	std::ignore = scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		int a, b;
		std::ignore = scanf("%d %d", &a, &b);
		--a, --b;
		int d = dist(&nodes[a], &nodes[b]);
		printf("%d\n", d);
	}
	return 0;
}
