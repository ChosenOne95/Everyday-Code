/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.


*/
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		map<char, int> p2i;
		map<string, int> w2i;
		istringstream in(str);// ������
		int i = 0, n = pattern.size();
		for (string word; in >> word; ++i) {
			if (i == n || p2i[pattern[i]] != w2i[word])
				return false;
			p2i[pattern[i]] = w2i[word] = i + 1;//ʵ���Ͽ��Կ���pattern�е��ַ���str�еĵ�����һһ��Ӧ�Ĺ�ϵ������Ӧʱ��˵��������pattern
		}
		return i == n;//������һ��word��ƥ��pattern�����
	}
};