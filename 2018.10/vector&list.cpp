/*
	vector顺序存储，随机访问快
	list链表存储，插入删除快
	deque占用内存多，兼具两者优点

	注意：
	1.vector严格顺序存储
	2.list的迭代器只能做++或--运算，要一次移动多个位置使用advance(iterator,offset)
	3.注意迭代器失效问题
	4.尤其注意list的删除时接收新地址的问题
*/
#include<iostream>
#include<vector>
#include<list>
using namespace std;

void DisplayVector(vector<int> &v){
	cout << "capacity:" << v.capacity() << endl;//capacity 为不重新分配内存下vector能容纳的元素个数
	cout << "size:" << v.size() << endl;//size是vector当前有的元素个数
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
	//声明空vector
	vector<int>v;
	DisplayVector(v);
	
	//五个元素均为66，第二个参数不写默认是零
	vector<int> v1(5,66);
	DisplayVector(v1);
	
	//v2的size为5，v2被初始化为a的5个值。后一个指针要指向将被拷贝的末元素的下一位置。
	int a[5] = { 0, 1, 2, 3, 3 }; 
	vector<int> v2(a, a + 5);
	
	/*
	//at()函数返回指定位置的值并可判断是否越界。在visual studio 中会引发中断异常
	for (int i = 0; i < v1.size() + 1; i++){
		v1.at(i) = i;
		//v1[i] = i;
		cout << v1.at(i) << '\t';
	}
	cout << endl;
	*/
	
	//push_back在vector后面插入新值，重新分配内存，pop_back删除末尾的元素
	for (int i = 0; i < 10; i++){
		v2.push_back(i);		
	}
	DisplayVector(v2);
	
	//判断vector是否为空
	cout << "v.empty()=" << v.empty() << endl;

	//迭代器访问vector	
	vector<int>::iterator ite = v2.begin();

	for (ite; ite != v2.end(); ite++){
		cout << *ite << '\t';
	}
	cout << endl;
	
	//利用insert向vector中插入元素
	ite = find(v2.begin(), v2.end(), 5);
	v2.insert(ite, 3, 666);
	v2.insert(v2.begin() + 3, 2, 333);
	DisplayVector(v2);

	//清空v2中的元素
	v2.clear();
	DisplayVector(v2);
	
	/*
	插入位置的迭代器一般最好为：

		begin()或 end()返回的
		STL 算法(如find函数)的返回位,find可用于查找元素，然后在这个位置插入另一个元素(这将导致查找的元素向后移).
		事实是size()为0的vector插入位置如果写begin()+pos或者end()+pos，均会报越界错误。
		不太懂的是既然capacity不为零，说明已经分配好了空间，为什么会有越界错误。
		也许是因为vector是严格要求顺序存储。
		当然要想在头尾插入最好用deque，用法和vector基本相同。
		要想在数组中频繁插入删除，使用list。
	*/
	
	//初始化list
	list<int>l1(10);
	list<int>l2(10, 66);
	DisplayList(l2);

	//声明迭代器
	list<int>::const_iterator con_ite_list;
	list<int>::iterator ite_list=l2.begin();

	//插入元素，头尾插入同vector、deque，
	//list的迭代器不是随机访问迭代器，是链表中的指针，只能ite++或者ite--
	//要运算list的迭代器，使用advance(ite,offset),注意不要越界
	advance(ite_list, 5);
	l2.insert(ite_list, 555);
	DisplayList(l2);

	//删除元素,可见插入后迭代器仍指向原来指向的元素而不是位置，而vector插入后迭代器则指向新插入的元素，也就是原来的位置
	//注意警惕erase陷阱，删除后接收新的地址值。
	ite_list=l2.erase(--ite_list);
	DisplayList(l2);

	//list排序,默认升序，降序可以vector.reverse()反转
	l2.insert(++l2.begin(), 555);
	l2.sort();
	DisplayList(l2);

	//二维vector,不再赘述，参考https://blog.csdn.net/a819825294/article/details/52088732
	vector<vector<int>> num;
	getchar();
	return 0;
}