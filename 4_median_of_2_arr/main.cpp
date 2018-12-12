#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	bool odd = (nums1.size() + nums2.size()) % 2;
	size_t target = (nums1.size() + nums2.size() - 1) / 2;

	auto beg1 = nums1.cbegin(), beg2 = nums2.cbegin();
	vector<int> *p1 = &nums1, *p2 = &nums2;

	while (true) {
		if (beg1 == p1->cend() || beg2 == p2->end()) {
			auto b = beg1 == p1->cend() ? beg2 : beg1;
			if (odd)
				return *(b + target);
			
			return (*(b + target) + *(b + target + 1)) / (double) 2;
		}
		
		if (*beg1 == *beg2) {
			if (target == 0)
				return *beg1;
			++beg1;
			--target;
			continue;
		}

		if (*beg1 > *beg2) {
			swap(p1, p2);
			swap(beg1, beg2);
		}

		if (!target) {
			if (odd)
				return *beg1;
			if (beg1 + 1 == p1->end())
				return (*beg1 + *beg2) / (double) 2;

			return (*beg1 + min(*(beg1 + 1), *beg2)) / (double) 2;
		}

		vector<int>::const_iterator it = lower_bound(beg1, p1->cend(), *beg2);
		--it;
		if (it == beg1) {
			--target;
			++beg1;
			continue;
		}

		cout << "distance is " << distance(beg1, it) << endl;

		if (distance(beg1, it) + 1 > (unsigned int)target) {
			if (odd)
				return *(beg1 + target);
			if (beg1 + target + 1 == p1->end())
				return (*(beg1 + target) + *beg2) / (double)2;
			else
				return (*(beg1 + target) + min(*beg2, *(beg1 + target + 1))) / (double)2;
			break;
		}

		target -= distance(beg1, it) + 1;
		beg1 = it + 1;
	}
}

int main(int argc, char **argv) {
	vector<int> n1{3};
	vector<int> n2{1, 2, 4};

	cout << "median is " << findMedianSortedArrays(n1, n2) << endl;

	return 0;
}
