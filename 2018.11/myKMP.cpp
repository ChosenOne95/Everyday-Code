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

void KmpIndex(string s, string p, vector<int> next)
{
	int i = 0;
	int j = 0;
	int sLen = s.length();
	int pLen = p.length();
	while (i < sLen && j < pLen)
	{
		//�����j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]��������i++��j++    
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//�����j != -1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���S[i] != P[j]�������� i ���䣬j = next[j]    
			//next[j]��Ϊj����Ӧ��nextֵ      
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