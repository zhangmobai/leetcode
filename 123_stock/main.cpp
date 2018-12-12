#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct Profits {
	int p1{0};
	int p2{0};
};

int maxProfit(vector<int>& prices) {
	if (prices.size() <= 1) {
		return 0;
	}

	vector<Profits> profits(prices.size());

	int max_tmp = -prices[0];
	int min_value = prices[0];

	//(i,p2) = max((i-1,p2), max((j,p1) + prices[i] - prices[j]) over all j);

	for (vector<int>::size_type i = 1; i != prices.size(); ++i) {
		profits[i].p1 = max(profits[i - 1].p1, prices[i] - min_value);

		profits[i].p2 = max(profits[i - 1].p2, max_tmp + prices[i]);

		max_tmp = max(max_tmp, profits[i].p1 - prices[i]);
		min_value = min(min_value, prices[i]);
	}

	return profits.rbegin()->p2;
}

int main(int argc, char **argv) {
	//vector<int> prices{1, 2};
	//vector<int> prices{2};
	vector<int> prices{10,9,8,7,6,5,4,3,2,1};
	cout << "Max profit: " << maxProfit(prices) << endl;
	return 0;
}
