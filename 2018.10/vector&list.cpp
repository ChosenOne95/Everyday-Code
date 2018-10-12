/*
	vector˳��洢��������ʿ�
	list����洢������ɾ����
	dequeռ���ڴ�࣬��������ŵ�

	ע�⣺
	1.vector�ϸ�˳��洢
	2.list�ĵ�����ֻ����++��--���㣬Ҫһ���ƶ����λ��ʹ��advance(iterator,offset)
	3.ע�������ʧЧ����
	4.����ע��list��ɾ��ʱ�����µ�ַ������
*/
#include<iostream>
#include<vector>
#include<list>
using namespace std;

void DisplayVector(vector<int> &v){
	cout << "capacity:" << v.capacity() << endl;//capacity Ϊ�����·����ڴ���vector�����ɵ�Ԫ�ظ���
	cout << "size:" << v.size() << endl;//size��vector��ǰ�е�Ԫ�ظ���
	cout << "elements:" << endl;
	for (int i = 0; i < v.size(); i++){
		cout << i<<':'<<v[i] << '\t';
	}
	cout << endl;
}
void DisplayList(list<int> &l){
	list<int>::iterator ite = l.begin();
	for (ite; ite != l.end(); ite++){
		cout << distance(l.begin(),ite) << ":" << *ite << '\t';
	}
	cout << endl;
}
int main(){
	//������vector
	vector<int>v;
	DisplayVector(v);
	
	//���Ԫ�ؾ�Ϊ66���ڶ���������дĬ������
	vector<int> v1(5,66);
	DisplayVector(v1);
	
	//v2��sizeΪ5��v2����ʼ��Ϊa��5��ֵ����һ��ָ��Ҫָ�򽫱�������ĩԪ�ص���һλ�á�
	int a[5] = { 0, 1, 2, 3, 3 }; 
	vector<int> v2(a, a + 5);
	
	/*
	//at()��������ָ��λ�õ�ֵ�����ж��Ƿ�Խ�硣��visual studio �л������ж��쳣
	for (int i = 0; i < v1.size() + 1; i++){
		v1.at(i) = i;
		//v1[i] = i;
		cout << v1.at(i) << '\t';
	}
	cout << endl;
	*/
	
	//push_back��vector���������ֵ�����·����ڴ棬pop_backɾ��ĩβ��Ԫ��
	for (int i = 0; i < 10; i++){
		v2.push_back(i);		
	}
	DisplayVector(v2);
	
	//�ж�vector�Ƿ�Ϊ��
	cout << "v.empty()=" << v.empty() << endl;

	//����������vector	
	vector<int>::iterator ite = v2.begin();

	for (ite; ite != v2.end(); ite++){
		cout << *ite << '\t';
	}
	cout << endl;
	
	//����insert��vector�в���Ԫ��
	ite = find(v2.begin(), v2.end(), 5);
	v2.insert(ite, 3, 666);
	v2.insert(v2.begin() + 3, 2, 333);
	DisplayVector(v2);

	//���v2�е�Ԫ��
	v2.clear();
	DisplayVector(v2);
	
	/*
	����λ�õĵ�����һ�����Ϊ��

		begin()�� end()���ص�
		STL �㷨(��find����)�ķ���λ,find�����ڲ���Ԫ�أ�Ȼ�������λ�ò�����һ��Ԫ��(�⽫���²��ҵ�Ԫ�������).
		��ʵ��size()Ϊ0��vector����λ�����дbegin()+pos����end()+pos�����ᱨԽ�����
		��̫�����Ǽ�Ȼcapacity��Ϊ�㣬˵���Ѿ�������˿ռ䣬Ϊʲô����Խ�����
		Ҳ������Ϊvector���ϸ�Ҫ��˳��洢��
		��ȻҪ����ͷβ���������deque���÷���vector������ͬ��
		Ҫ����������Ƶ������ɾ����ʹ��list��
	*/
	
	//��ʼ��list
	list<int>l1(10);
	list<int>l2(10, 66);
	DisplayList(l2);

	//����������
	list<int>::const_iterator con_ite_list;
	list<int>::iterator ite_list=l2.begin();

	//����Ԫ�أ�ͷβ����ͬvector��deque��
	//list�ĵ���������������ʵ��������������е�ָ�룬ֻ��ite++����ite--
	//Ҫ����list�ĵ�������ʹ��advance(ite,offset),ע�ⲻҪԽ��
	advance(ite_list, 5);
	l2.insert(ite_list, 555);
	DisplayList(l2);

	//ɾ��Ԫ��,�ɼ�������������ָ��ԭ��ָ���Ԫ�ض�����λ�ã���vector������������ָ���²����Ԫ�أ�Ҳ����ԭ����λ��
	//ע�⾯��erase���壬ɾ��������µĵ�ֵַ��
	ite_list=l2.erase(--ite_list);
	DisplayList(l2);

	//list����,Ĭ�����򣬽������vector.reverse()��ת
	l2.insert(++l2.begin(), 555);
	l2.sort();
	DisplayList(l2);

	//��άvector,����׸�����ο�https://blog.csdn.net/a819825294/article/details/52088732
	vector<vector<int>> num;
	getchar();
	return 0;
}