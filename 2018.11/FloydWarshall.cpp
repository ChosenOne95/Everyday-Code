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
	for (int i = 0; i < nNodes; ++i) {
		for (int j = 0; j < nNodes; ++j) {
			cout << " " << setw(3) << W[i][j];
		}
		cout << endl;
	}
}

int main(void) {
	cout << "Floyd-Warshall algorithm for Directed Acyclic Graph: " << endl;
	while (true) {

		int nNodes;
		cout << "Number of Nodes: ";
		cin >> nNodes;

		vector<vector<int> > Wgt(nNodes, vector<int>(nNodes, INF));
		for (int i = 0; i < nNodes; ++i)
			Wgt[i][i] = 0;

		int nEdges;
		cout << "Number of Edges: ";
		cin >> nEdges;

		cout << "Src  Dest  Dist(< " << INF << "): " << endl;
		for (int i = 0; i < nEdges; ++i) {
			int src, dest, dist;
			cout << "[" << i << "]: ";
			cin >> src >> dest >> dist;
			Wgt[src][dest] = dist;
		}

		for (int i = 0; i < nNodes; ++i) {
			for (int j = 0; j < nNodes; ++j) {
				if (Wgt[i][j] != INF)
					cout << " " << setw(3) << Wgt[i][j];
				else
					cout << " " << "INF";
			}
			cout << endl;
		}

		//O(n^3), amazing, the fastest ever known!!
		while (true) {
			ch_status(Wgt, nNodes);
			display(Wgt);
			system("pause");
		}
	}
	return 0;
}
