#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
	static vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> r;
		const uint64_t size = 1 << nums.size();

		for (unsigned int i = 0; i != size; ++i) {
			vector<int> e;
			for (vector<int>::size_type j = 0; j != nums.size(); ++j) {
				if (i & (1 << j))
					e.push_back(nums[j]);
			}
			r.push_back(e);
		}

		return r;
	}
};

int main (int argc, char **argv) {
	vector<int> v({1,2,3});
	vector<vector<int>> r = Solution::subsets(v);

	for (auto &e : r) {
		cout << "[ ";
		for (auto &i : e)
			cout << i << " ";
		cout << " ]\n";
	}

	return 0;
}
