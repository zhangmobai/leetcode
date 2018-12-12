#include <iostream>
#include <stack>
#include <string>
#include <vector>


using namespace std;

void generate(int n_left, int n_right, stack<char> &st, vector<string> &r, string &s, string::size_type i) {
	if (n_left == 0 && n_right == 0) {
		if (st.empty())
			r.push_back(s);
		return;
	}

	if (st.empty()) {
		st.push('(');
		s[i++] = '(';
		generate(n_left - 1, n_right, st, r, s, i);
		s[--i] = '\0';
		st.pop();
		return;
	}

	if (n_left) {
		st.push('(');
		s[i++] = '(';
		generate(n_left - 1, n_right, st, r, s, i);
		s[--i] = '\0';
		st.pop();
	}

	if (n_right) {
		bool popped = false;
		if (st.top() == '(') {
			st.pop();
			popped = true;
		}
		s[i++] = ')';
		generate(n_left, n_right - 1, st, r, s, i);
		s[--i] = '\0';

		if (popped)
			st.push('(');
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> r;
	stack<char> st;
	string s(n * 2, '\0');
	generate(n, n, st, r, s, 0);
	return r;
}

int main(int argc, char **argv) {
	vector<string> r = generateParenthesis(4);
	for (auto s : r)
		cout << s << endl;

	return 0;
}
