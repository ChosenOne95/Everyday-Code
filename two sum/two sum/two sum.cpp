// two sum.cpp : 定义控制台应用程序的入口点。
//
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include "stdafx.h"
#include<Vector>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//int n=sizeof(nums)/sizeof(nums[0]);
		int n = nums.size();
		vector<int> t;
		for (int a = 0; a<n; a++){
			for (int b = a + 1; b<n; b++){
				if (nums[a] + nums[b] == target){
					t.push_back(a);
					t.push_back(b);
					break;
				}
				else{
					;
				}
			}
		}
		for (int i = 0; i < t.size(); i++){
			cout << t[i] <<"\t";
		}
		cout << endl;
		return t;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector <int> Nums;
	Solution s;
	int target = 0;
	int temp = 0;
	char run = 'y';
	do{
		cout << "enter the numbers:  " << endl;
		do{
			cin >> temp;
			Nums.push_back(temp);
		} while (getchar() != '\n');//数字之间用空格隔开，回车结束输入
		cout << "enter the target: " << endl;
		cin >> target;
		s.twoSum(Nums, target);
		Nums.clear();
		target = 0;
		cout << "coutinue?(Y/N)" << endl;
		cin >> run;
	} while (run == 'Y'||run=='y');
	/*
	cout << "enter the numbers:  " << endl;
	while (getchar() != '\n'){
		cin >> temp;
		Nums.push_back(temp);
	}
	cout << "enter the target: " << endl;
	cin >> target;
	s.twoSum(Nums, target);
	*/
	return 0;
}

