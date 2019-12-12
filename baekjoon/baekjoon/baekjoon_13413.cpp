/*
baekjoon algorithm
Question number: 13413
https://www.acmicpc.net/problem/13413
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int T; //테스트 데이터 갯수
int N; //말의 개수
int WB = 0;
int BW = 0;
int ans;

char s[100001]; //초기 말의 상태
char d[100001]; //목표 말의 상태

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