#include <iostream>
#include <cassert>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	static int lengthOfLongestSubstring(string s) {
		unsigned int g_max_index = 0;
		unsigned int g_max_size = 0;
		unsigned int max_index = 0;
		unsigned int max_size = 0;
		unordered_map<char, unsigned int> m;

		for (unsigned int i = 0; i != s.size(); ++i) {
			if (m.find(s[i]) == m.end() || m[s[i]] < max_index) {
				m[s[i]] = i;
				max_size++;
				continue;
			}

			if (max_size > g_max_size) {
				g_max_size = max_size;
				g_max_index = max_index;
			}

			max_size = max_size - (m[s[i]] - max_index);
			max_index = m[s[i]] + 1;
			m[s[i]] = i;
		}
		if (max_size > g_max_size) {
			g_max_size = max_size;
			g_max_index = max_index;
		}

		cout << "max substring without repeated chars: ";
		for (unsigned int i = g_max_index; i != g_max_index + g_max_size; ++i)
			cout << s[i];
		cout << endl;
		return g_max_size;
	}
};

int main (int argc, char **argv) {
	string s = "abcabcbb";
	cout << s << " : " << Solution::lengthOfLongestSubstring(s) << endl;
	s = "bbbbb";
	cout << s << " : " << Solution::lengthOfLongestSubstring(s) << endl;
	s = "pwwkew";
	cout << s << " : " << Solution::lengthOfLongestSubstring(s) << endl;
	s = "c";
	cout << s << " : " << Solution::lengthOfLongestSubstring(s) << endl;
	return 0;
}
