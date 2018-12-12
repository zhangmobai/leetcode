#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
	int n=nums.size();
	int fromBegin=1;
	int fromLast=1;
	vector<int> res(n,1);

	for(int i=0;i<n;i++){
		res[i]*=fromBegin;
		fromBegin*=nums[i];
		res[n-1-i]*=fromLast;
		fromLast*=nums[n-1-i];
	}
	return res;
}

int main(int argc, char **argv) {
	vector<int> v{1, 2, 3, 4};
	vector<int> r = productExceptSelf(v);
	for (auto i: r)
		cout << i << " ";
	cout << endl;
	return 0;
}
