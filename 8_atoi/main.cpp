#include <iostream>
#include <limits>

using namespace std;

int myAtoi(string str) {
	int r = 0;
	bool negative = false;
	string::size_type i = 0;
	while (str[i] == ' ')
		++i;

	if (str[i] == '-') {
		++i;
		negative = true;
	} else if (str[i] == '+') {
		++i;
	}

	while (str[i] <= '9' && str[i] >= '0') {
		if (r > numeric_limits<int>::max() / 10)
			return negative ? numeric_limits<int>::min() : numeric_limits<int>::max();
		if (r == numeric_limits<int>::max() / 10) {
			if (str[i] <= '7') {
				r = r * 10 + str[i++] - '0';
				continue;
			}
			return negative ? numeric_limits<int>::min() : numeric_limits<int>::max();
		}
		r = r * 10 + (str[i++] - '0');
	}

	if (negative) {
		r = -r;
	}

	return r;
}

int main(int argc, char **argv) {
	string s{"-2147483647"};
	int r = myAtoi(s);
	cout << r << endl;
	return 0;
}
