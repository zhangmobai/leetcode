#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums) {
	int max_sum = numeric_limits<int>::min();
	int pre_sum = -1;
	for (vector<int>::size_type i = 0; i != nums.size(); ++i) {
		if (pre_sum < 0)
			pre_sum = nums[i];
		else
			pre_sum += nums[i];

		max_sum = max(max_sum, pre_sum);
	}

	return max_sum;
}

int main(int argc, char **argv) {
	vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};

	cout << maxSubArray(v) << endl;
	
	return 0;
}
