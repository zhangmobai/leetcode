#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *h = NULL, *l1_cursor = l1, *l2_cursor = l2;
		ListNode *parent = NULL;
		int carry = 0;

		while (true) {
			if (l1_cursor == NULL && l2_cursor == NULL) {
				if (carry == 0)
					break;
				ListNode *n = new ListNode(1);
				if (!parent)
					h = n;
				else 
					parent->next = n;
				break;
			}
				
			int v = 0;

			if (l1_cursor == NULL) {
				v = l2_cursor->val + carry;
				l2_cursor = l2_cursor->next;
			} else if (l2_cursor == NULL) {
				v = l1_cursor->val + carry;
				l1_cursor = l1_cursor->next;
			} else {
				v = l1_cursor->val + l2_cursor->val + carry;
				l1_cursor = l1_cursor->next;
				l2_cursor = l2_cursor->next;
			}

			carry = v / 10;
			ListNode *n = new ListNode(v %= 10);

			if (!parent) {
				h = n;
			} else {
				parent->next = n;
			}

			parent = n;
		}

		return h;
	}
};

int main (int argc, char **argv) {
	ListNode *l1_1 = new ListNode(2);
	ListNode *l1_2 = new ListNode(4);
	ListNode *l1_3 = new ListNode(3);
	l1_1->next = l1_2;
	l1_2->next = l1_3;

	ListNode *l2_1 = new ListNode(5);
	ListNode *l2_2 = new ListNode(6);
	ListNode *l2_3 = new ListNode(4);
	l2_1->next = l2_2;
	l2_2->next = l2_3;

	ListNode *l3 = Solution::addTwoNumbers(l1_1, l2_1);
	ListNode *c = l3;
	while (c) {
		cout << c->val << "->";
		c = c->next;
	}

	return 0;
}
