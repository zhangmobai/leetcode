#include <iostream>
#include <string>

using namespace std;

bool matchHere(const char *s, const char *p) {
	cout << "trying to match '" << s << "' and '" << p << "'" << endl;
	if (!*s) {
		if (!*p)
			return true;

		if (*p == '*')
			return matchHere(s, p + 1);

		return false;
	}

	if (!*p)
		return !*s;

	if (*p == '?' || *s == *p)
		return matchHere(s + 1, p + 1);

	if (*p != '*')
		return false;

	// *p == *
	if (!*(p + 1))
		return true;

	while (*p == '*')
		++p;

	do {
		if (matchHere(s, p))
			return true;
	} while (*(s++));

	return false;
}

int main(int argc, char **argv) {
	const char *s, *p;
#if 0
	s = "bbbbbbbabbaabbabbbbaaabbabbabaaabbababbbabbbabaaabaab";
	p = "b*b*ab**ba*b**b***bba";
#endif
	s = "aaba";
	p = "?***";
	cout << s << " matches " << p << ": " << (matchHere(s, p) ? "true" : "false") << endl;

	return 0;
}
