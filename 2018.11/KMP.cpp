/*
�ַ���ƥ��KMP����
*/
#include <iostream>
#include <string>
#include<vector>
#include <sstream>
using namespace std;

//��ģʽ��t��next����ֵ����������next��
//�Ż������next������
vector<int> GetNext(string ps) {
	string p = ps;
	vector<int> next(p.length());
	next[0] = -1;
	int j = 0;
	int k = -1;
	while (j < p.length() - 1) {
		//p[k]��ʾǰ׺��p[j]��ʾ��׺
		if (k == -1 || p[k] == p[j]) {
			next[++j] = ++k;//����p[k] == p[j]ʱ��next[j+1] == next[j] + 1=k+1
		}
		else {
			k = next[k];
		}
	}
	return next;
}

//t�ǿգ�1<=pos<=strlength(s)
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