/*
baekjoon algorithm
Question number: 13413
https://www.acmicpc.net/problem/13413
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int T; //�׽�Ʈ ������ ����
int N; //���� ����
int WB = 0;
int BW = 0;
int ans;

char s[100001]; //�ʱ� ���� ����
char d[100001]; //��ǥ ���� ����

int main(int argc, char* argv[])
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		scanf("%s", s);
		scanf("%s", d);

		for (int j = 0; j < N; j++)
		{
			if (s[j] == 'W' && d[j] == 'B')
				WB++;
			else if (s[j] == 'B' && d[j] == 'W')
				BW++;
		}

		ans = max(WB, BW);
		printf("%d\n", ans);
		WB = 0;
		BW = 0;
	}

	return 0;
}