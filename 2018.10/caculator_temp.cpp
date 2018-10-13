/*
构建之法第一章习题一，实现自动生成四则运算的算式并判断用户计算的正误。
计划分四步走：
1.自动生成算式
2.输入算式转换为逆波兰式
3.计算算式结果
4.与用户输入比对判断正误
*/
#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<map>
using namespace std;

//将中缀表达式转换为逆波兰式
stack<string> ConvertToRpn(string s, map<string, int>p, map<char, int>p_char){
	int length = s.length();
	stringstream ss;
	string temp_s = "";
	string temp_for_push;
	double temp_n = 0;
	stack<string>sk1, sk2;
	sk1.push("#");
	for (int i = 0; i < length;){
		if (isdigit(s[i])){//判断字符是否是0~9的数字
			while (isdigit(s[i]) || s[i] == '.'){
				temp_s = temp_s + s[i];
				i++;
			}
			ss << temp_s;
			ss >> temp_n;
			sk2.push(temp_s);
			temp_s = "";
		}
		else{
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
				if (p_char[s[i]] >p[sk1.top()]){
					temp_for_push.clear();
					temp_for_push = temp_for_push + s[i];
					sk1.push(temp_for_push);
					i++;
				}
				else{
					while (p_char[s[i]] <= p[sk1.top()]){
						string temp_c = sk1.top();
						sk1.pop();
						sk2.push(temp_c);
					}
					temp_for_push.clear();
					temp_for_push = temp_for_push + s[i];
					sk1.push(temp_for_push);
					i++;
				}
			}
			else if (s[i] == '('){
				temp_for_push.clear();
				temp_for_push = temp_for_push + s[i];
				sk1.push(temp_for_push);
				i++;
			}
			else if (s[i] == ')'){
				while (sk1.top() != "("){
					sk2.push(sk1.top());
					sk1.pop();
				}
				sk1.pop();
				i++;
			}
		}
	}
	return sk2;
}
int main(){
	map<string, int> priorites;
	priorites["+"] = 1;
	priorites["-"] = 1;
	priorites["*"] = 2;
	priorites["/"] = 2;
	priorites["^"] = 3;
	map<char, int> priorites_char;
	priorites_char['+'] = 1;
	priorites_char['-'] = 1;
	priorites_char['*'] = 2;
	priorites_char['/'] = 2;
	priorites_char['^'] = 3;
	string expression;
	stack<string> RPN;
	cout << "please enter the expression:" << endl;
	cin >> expression;
	RPN = ConvertToRpn(expression, priorites, priorites_char);//得到后缀表达式
	system("pause");
	return 0;
}