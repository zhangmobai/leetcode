#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	int min = numeric_limits<int>::max();
	int profit = 0;
	for (auto p: prices) {
		if (p <= min)
			min = p;
		if (p > min && p - min > profit)
			profit = p - min;
	}

	return profit;
}

int main(int argc, char **argv) {
	//vector<int> prices{7, 1, 5, 3, 6, 4};
	vector<int> prices{7, 6, 4, 3, 1};
	cout << maxProfit(prices);
	return 0;
}
