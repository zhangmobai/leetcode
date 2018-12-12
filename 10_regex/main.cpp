#include <iostream>
#include <string>

using namespace std;

bool isMatch(const char *s, const char *p);

bool isMatchStar(char c, const char *p, const char *s) {
	do {
		if (isMatch(s, p))
			return true;
	} while (*s != '\0' && (*s++ == c || c == '.'));

	return false;
}

bool isMatch(const char *s, const char *p) {
	if (*p == '\0')
		return *s == '\0';

	if (p[1] == '*')
		return isMatchStar(*p, p + 2, s);

	if (*s != '\0' && (*p == '.' || *p == *s))
		return isMatch(s + 1, p + 1);

	return false;
}

/*
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b")
 */
int main(int argc, char **argv) {
	const char *s, *p;
#if 1
	s = "aa";
	p = "a";
	cout << s << " matches " << p << ": " << (isMatch(s, p) ? "true" : "false") << endl;
	s = "aa";
	p = "aa";
	cout << s << " matches " << p << ": " << (isMatch(s, p) ? "true" : "false") << endl;
	s = "aaa";
	p = "a.a";
	cout << s << " matches " << p << ": " << (isMatch(s, p) ? "true" : "false") << endl;
	s = "aaa";
	p = "aa";
	cout << s << " matches " << p << ": " << (isMatch(s, p) ? "true" : "false") << endl;
	s = "aa";
	p = "a*";
	cout << s << " matches " << p << ": " << (isMatch(s, p) ? "true" : "false") << endl;
	s = "aa";
	p = ".*";
	cout << s << " matches " << p << ": " << (isMatch(s, p) ? "true" : "false") << endl;
	s = "ab";
	p = ".*";
	cout << s << " matches " << p << ": " << (isMatch(s, p) ? "true" : "false") << endl;
	s = "aab";
	p = "c*a*b";
	cout << s << " matches " << p << ": " << (isMatch(s, p) ? "true" : "false") << endl;
#endif
	s = "abcd";
	p = "d*";
	cout << s << " matches " << p << ": " << (isMatch(s, p) ? "true" : "false") << endl;
	s = "aaa";
	p = "ab*a*c*a";
	cout << s << " matches " << p << ": " << (isMatch(s, p) ? "true" : "false") << endl;

	return 0;
}
