/*
	����֮����һ��ϰ��һ��ʵ���Զ����������������ʽ���ж��û����������
	�ƻ����Ĳ��ߣ�
	1.�Զ�������ʽ
	2.������ʽת��Ϊ�沨��ʽ
	3.������ʽ���
	4.���û�����ȶ��ж�����
*/
#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
#include<map>
using namespace std;

//����׺���ʽת��Ϊ�沨��ʽ
queue<string> ConvertToRpn(string s,map<string,int>p,map<char,int>p_char){
	int length = s.length();
	string temp_s="";
	string temp_for_push;
	stack<string>sk1;
	queue<string>sk2;
	sk1.push("#");
	for (int i = 0; i < length;){
		if (isdigit(s[i])){//�ж��ַ��Ƿ���0~9������
			while (isdigit(s[i]) || s[i] == '.'){
				temp_s = temp_s + s[i];
				i++;
			}
			sk2.push(temp_s);
			temp_s.clear();
		}
		else{
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'||s[i]=='^'){
				if (p_char[s[i]] >p[sk1.top()]){
					temp_for_push.clear();
					temp_for_push = temp_for_push + s[i];
					sk1.push(temp_for_push);
					i++;
				}
				else{
					while (p_char[s[i]] <= p[sk1.top()]){
						sk2.push(sk1.top());
						sk1.pop();
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
			else if(s[i]==')'){
				while (sk1.top() != "("){
					sk2.push(sk1.top());
					sk1.pop();
				}
				sk1.pop();
				i++;
			}
		}
		if (i == length){
			while (sk1.size() != 1){
				sk2.push(sk1.top());
				sk1.pop();
			}
		}
	}
	return sk2;
}
double calculate(double n1, double n2, char c){
	double result = 0;
	if (c == '+'){
		result = n1 + n2;
	}
	else if (c == '-'){
		result = n2 - n1;
	}
	else if (c == '*'){
		result = n1*n2;
	}
	else if (c == '/'){
		result = n2 / n1;
	}
	return result;
}
double operation(queue<string> q){
	stack<double> temp_for_digit;
	char temp_for_char;
	double temp_for_push = 0;
	double num1, num2;
	double temp_result = 0;
	int length = q.size();
	stringstream ss;
	while (q.size() != 0){
		if (isdigit(q.front()[0])){
			ss << q.front();
			ss >> temp_for_push;
			temp_for_digit.push(temp_for_push);
			q.pop();
			ss.clear();
		}
		else{
			temp_for_char = q.front()[0];
			q.pop();
			num1 = temp_for_digit.top();
			temp_for_digit.pop();
			num2 = temp_for_digit.top();
			temp_for_digit.pop();
			temp_result = calculate(num1, num2, temp_for_char);
			temp_for_digit.push(temp_result);
		}
	}
	return temp_result;
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
	queue<string> RPN;
	double result;
	cout << "please enter the expression:" << endl;
	cin >> expression;
	RPN = ConvertToRpn(expression,priorites,priorites_char);//�õ���׺���ʽ
	result = operation(RPN);
	system("pause");
	return 0;
}