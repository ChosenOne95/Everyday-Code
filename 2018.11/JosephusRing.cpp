#include<iostream>
#include<vector>
#include <algorithm>
#include<time.h>
using namespace std;
#define Num 41
#define KillMan 3
#define CLOCKS_PER_SEC ((clock_t)1000)
void Josephus(int alive)
{
	vector<int> man(Num);
	int count = 1;
	int i = 0, pos = -1;

	while (count <= Num)
	{
		do{
			pos = (pos + 1) % Num;
			if (man[pos] == 0)
			{
				i++;
			}
			if (i == KillMan)
			{
				i = 0;
				break;
			}
		} while (1);
		man[pos] = count;
		//cout << pos << "自杀，约瑟夫环编号" << man[pos] << endl;
		if (count % 2)
		{
			//cout << "->";
		}
		else
		{
			//cout << "->";
		}
		count++;
	}
	cout << endl;
	cout << alive << "存活的人应该排在：" << endl;
	alive = Num - alive;
	for (i = 0; i < Num; i++)
	{
		if (man[i]>alive)
		{
			cout << "初始编号" << i + 1 << "约瑟夫环编号" << man[i] << endl;
		}
	}
}
void MyJosephus(int alive)
{
	//list<int> man(Num);
	vector<int>man(Num);
	int i = 0, lived = 1, count = 0, dead = 0;
	while (man.size()-count > alive)
	{
		if (man[i] == 0)
		{
			if (lived == 3){
				lived = 1;
				man[i] = 1;
				//cout << i+1 << "  dead" << endl;
				count++;
			}
			else
			{
				lived++;
			}
			
		}
		i=(i+1)%Num;
	}
	for (int j = 0; j < Num; j++){
		if (man[j] == 0)
			cout << j+1 << "alived!" << endl;
	}
}
int main()
{
	clock_t StartT1, StartT2, EndT1, EndT2;
	StartT1 = clock();
	Josephus(2);
	EndT1 = clock();
	cout << "Josephus total time:" <<(double)(EndT1 - StartT1)/CLOCKS_PER_SEC << endl;
	StartT2 = clock();
	MyJosephus(2);
	EndT2 = clock();
	cout << "MyJosephus total time:" << (double)(EndT2 - StartT2)/CLOCKS_PER_SEC << endl;
	return 0;
}