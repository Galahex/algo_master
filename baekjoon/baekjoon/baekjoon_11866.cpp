/*
baekjoon algorithm
Question number: 11866
https://www.acmicpc.net/problem/11866
*/
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(int argc, char* argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);

	queue<int> Q;
	for (int i = 1; i <= n; i++)
		Q.push(i);
	int cnt = 1;
	printf("<");
	while (Q.size() > 1)
	{
		if (cnt % m == 0)
		{
			printf("%d, ", Q.front());
			Q.pop();
		}
		else
		{
			Q.push(Q.front());
			Q.pop();
		}
		cnt++;
	}
	printf("%d", Q.front());
	printf(">\n");

	return 0;
}