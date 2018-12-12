#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int> &nums) {
	vector<int>::size_type start = 0, end = nums.size(), mid = nums.size() / 2;
	for (;;) {
		if (end - start <= 1)
			break;

		if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
			break;

		if ((mid - start) % 2 == 0) {
			if (nums[mid - 1] == nums[mid])
				end = mid - 1;
			else
				start = mid + 1;
		} else {
			if (nums[mid - 1] == nums[mid])
				start = mid + 1;
			else
				end = mid - 1;
		}

		mid = start + (end - start)/2;
	}
	return nums[mid];
}

int main(int argc, char **argv) {
	//vector<int> v{1,1,2,3,3,4,4,8,8};
	//vector<int> v{3,3,7,7,10,11,11};
	vector<int> v{0,1,1};
	cout << singleNonDuplicate(v) << endl;
	return 0;
}
