/*
最短路问题，floyd warshall算法
https://blog.csdn.net/qq_21555605/article/details/46391605
*/

#include<iostream>
#include<cctype>
#include<sstream>
#include<string>
#include<algorithm>
#include<map>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<queue>

using namespace std;

const int INF = 100000000;

void ch_status(vector<vector<int> > & W, int nNodes) {
	//DP, just like bellmanford.
	for (int k = 0; k < nNodes; ++k) {
		for (int i = 0; i < nNodes; ++i) {
			for (int j = 0; j < nNodes; ++j) {
				if (W[i][j] > W[i][k] + W[k][j]) {
					W[i][j] = W[i][k] + W[k][j];
				}
			}
		}
	}
}

void display(const vector<vector<int> > & W) {
	int nNodes = W.size();
