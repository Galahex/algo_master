/*
baekjoon algorithm
Question number: 1005
https://www.acmicpc.net/problem/1005
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int N, K; //N: 건물 개수, K: 건물간의 건설순서 규칙

int main(int argc, char* argv[])
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &N, &K);

		int* time = new int[N + 1]; //건물별 건설시간
		int* DP = new int[N + 1];
		int* indegree = new int[N + 1];
		memset(DP, 0, sizeof(int) * (N + 1));
		memset(indegree, 0, sizeof(int) * (N + 1));

		vector<int>* order = new vector<int>[N + 1];
		queue<int> Q;

		for (int i = 1; i <= N; i++)
			scanf("%d", &time[i]);

		for (int i = 0; i < K; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			order[u].push_back(v);
			indegree[v]++;
		}

		for (int i = 1; i <= N; i++)
		{
			if (indegree[i] == 0)
				Q.push(i);
		}

		while (!Q.empty())
		{
			int p = Q.front();
			Q.pop();
			int size = order[p].size();
			for (int i = 0; i < size; i++)
			{
				if (DP[p] == 0)
					DP[p] = time[p];
				DP[order[p][i]] = max(DP[order[p][i]], DP[p] + time[order[p][i]]);
				indegree[order[p][i]]--;
				if (indegree[order[p][i]] == 0)
					Q.push(order[p][i]);
			}
		}

		int des;
		scanf("%d", &des);

		printf("%d\n", DP[des]);

		delete[] time;
		delete[] DP;
		delete[] order;
		delete[] indegree;
	}

	return 0;
}