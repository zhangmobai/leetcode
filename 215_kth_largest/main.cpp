#include <iostream>
#include <vector>

using namespace std;

int kth(vector<int> &nums, int start, int end, int k) {
	int i = start, j = start + 1;
	int pivot = nums[start];
	while (j != end) {
		while (j != end && nums[j] < pivot)
			++j;

		if (j == end)
			break;

		++i;
		swap(nums[i], nums[j]);
		++j;
	}
	swap(nums[start], nums[i]);

	if (i - start + 1 == k)
		return nums[i];
	if (i - start + 1 < k)
		return kth(nums, i + 1, end, k - (i - start  + 1));

	return kth(nums, start, i, k);
}

int findKthLargest(vector<int> &nums, int k) {
	return kth(nums, 0, nums.size(), k);
}

int main(int argc, char **argv) {
	vector<int> v{3,2,1,5,6,4};
	cout << findKthLargest(v, 2) << endl;
	return 0;
}
