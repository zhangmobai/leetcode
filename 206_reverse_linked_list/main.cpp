#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) { }
};

ListNode *reverseList(ListNode *head) {
	ListNode *p = head;
	ListNode *pre = nullptr;

	while (p) {
		ListNode *pnext = p->next;
		p->next = pre;
		pre = p;
		p = pnext;
	}

	return pre;
}

int main(int argc, char **argv) {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);

	head = reverseList(head);

	while (head) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
	return 0;
}
