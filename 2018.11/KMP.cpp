/*
字符串匹配KMP方法
*/
#include <iostream>
#include <string>
#include<vector>
#include <sstream>
using namespace std;

//求模式串t的next函数值并存入数组next中
//优化过后的next数组求法
vector<int> GetNext(string ps) {
	string p = ps;
	vector<int> next(p.length());
	next[0] = -1;
	int j = 0;
	int k = -1;
	while (j < p.length() - 1) {
		//p[k]表示前缀，p[j]表示后缀
		if (k == -1 || p[k] == p[j]) {
			next[++j] = ++k;//即当p[k] == p[j]时，next[j+1] == next[j] + 1=k+1
		}
		else {
			k = next[k];
		}
	}
	return next;
}

//t非空，1<=pos<=strlength(s)
int KmpIndex(string s, string t, int pos, vector<int>next)
{
	int i = pos, j = 1;
	while (i <= s[0] && j <= t[0])
	{
		if (j == 0 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j > t[0])
	{
		return i = t[0];
	}
	else
	{
		return 0;
	}
}
int main()
{
	string s = "abcdabd";
	string t = "bbc abcdab abcdabcdabde";
	vector<int> next(255);
	next = GetNext(s);
	KmpIndex(t, s, 0, next);
	return 0;
}