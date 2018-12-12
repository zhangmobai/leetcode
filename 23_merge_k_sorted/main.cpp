#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
	auto comp = [](const ListNode *l, const ListNode *r) { return l->val > r->val; };
	priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> heap(comp);

	ListNode *head = NULL, *c = NULL;;

	for (auto l: lists)
		heap.push(l);

	while (!heap.empty()) {
		auto t = heap.top();
		cout << t->val << endl;
			
		if (!head)
			head = c = t;
		else {
			c->next = t;
			c = c->next;
		}
		heap.pop();

		if (t->next)
			heap.push(t->next);
	}

	return head;
}

int main(int argc, char **argv) {
	vector<ListNode *> lists;
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(5);
	lists.push_back(l1);
	ListNode *l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);
	lists.push_back(l2);
	ListNode *l3 = new ListNode(2);
	l3->next = new ListNode(6);
	lists.push_back(l3);

	ListNode *m = mergeKLists(lists);

	ListNode *c = m;
	while (c) {
		cout << c->val << " ";
		c = c->next;
	}
	cout << endl;
	
	return 0;
}
