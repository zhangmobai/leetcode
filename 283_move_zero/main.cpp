#include <iostream>
#include <vector>

using namespace std;

void move_zeros(vector<int> &v) {
	int j = -1;
	for (vector<int>::size_type i = 0;
	     i != v.size();
	     ++i) {
		if (j == -1) {
			if (v[i] == 0)
				j = i;
			continue;
		} else if (v[i] == 0)
			continue;

		swap(v[i], v[j]);
		++j;
	}

	for (auto n : v)
		cout << n << " ";
	cout << endl;
}

int main(int argc, char **argv) {
	vector<int> v{0, 1, 0, 3, 12};
	move_zeros(v);
	return 0;
}
