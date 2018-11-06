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

void KmpIndex(string s, string p, vector<int> next)
{
	int i = 0;
	int j = 0;
	int sLen = s.length();
	int pLen = p.length();
	while (i < sLen && j < pLen)
	{
		//①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++    
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]    
			//next[j]即为j所对应的next值      
			j = next[j];
		}
	}
	if (j == pLen)
		//cout << i - j <<s[i-j]<< endl;
		cout << i - j << string (s, i - j, pLen) << endl;
	else
		cout << "not found" << endl;

}
int main()
{
	string s = "abcdabd";
	string t = "bbc abcdab abcdabcdabde";
	vector<int> next(255);
	next = GetNext(s);
	KmpIndex(t, s, next);
	return 0;
}