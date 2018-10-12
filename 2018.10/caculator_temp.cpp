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
#include<map>
using namespace std;

//����׺���ʽת��Ϊ�沨��ʽ
string ConvertToRpn(string s,map<string,int>p,map<char,int>p_char){
	int length = s.length();
	stringstream ss;
	string temp_s="";
	string temp_for_push;
	double temp_n = 0;
	stack<string>sk1,sk2;
	sk1.push("#");
	for (int i = 0; i < length;){
		if (isdigit(s[i])){//�ж��ַ��Ƿ���0~9������
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
			else if(s[i]==')'){
				while (sk1.top() != "("){
					sk2.push(sk1.top());
					sk1.pop();
				}
				sk1.pop();
				i++;
			}
			/*
			switch (s[i]){
			case"+":
			case"-":
			case"*":
			case"/":
				if (p[s[i]] >p[sk1.top()]){
					sk1.push(s[i]);
					i++;
				}
				else{
					while (p[s[i]] <= sk1.top()){
						string temp_c = sk1.top();
						sk1.pop();
						sk2.push(temp_c);
					}
					sk1.push(s[i]);
					i++;
				}
			case'(':
				sk1.push(s[i]);
				i++;
			case')':
				while (sk1.top() != '('){
					sk2.push(sk1.top());
					sk1.pop();
				}
				sk1.pop();
				i++;
			}
			*/
		}

	}
	string RPN = "";
	while (sk2.size() != 0){
		cout << sk2.top() << '\b';
		sk2.pop();
	}
	return RPN;
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
	cout << "please enter the expression:" << endl;
	cin >> expression;
	expression = ConvertToRpn(expression,priorites,priorites_char);
	cout << "the RPN expression is:" << endl;
	system("pause");
	return 0;
}