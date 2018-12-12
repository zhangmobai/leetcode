#include <iostream>
#include <stack>

using namespace std;

char matching(char c) {
	switch (c) {
		case ')':
			return '(';
		case '}':
			return '{';
		case ']':
			return '[';
		default:
			return '\0';
	}
}

bool isValid(string s) {
	stack<char> st;
	for (auto c: s) {
		if (st.empty() == false && st.top() == matching(c)) {
			st.pop();
		} else {
			st.push(c);
		}
	}

	return st.empty();
}


int main(int argc, char **argv) {
	string s = "()";
	cout << isValid(s) << endl;

	return 0;
}
