/*
baekjoon algorithm
Question number: 15953
https://www.acmicpc.net/problem/15953
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main(int agrc, char* agrv[])
{
	int T; //횟수
	int a, b; // 17년, 18년 순위
	int a_reward; //17년 획득 상금
	int b_reward; //18년 획득 상금

	int reward_17th[7] = { 0, 1, 3, 6, 10, 15, 21 }; //17년도 순위 정보
	int prize_17th[6] = { 500, 300, 200, 50, 30, 10 }; //17년도 상금 정보

	int reward_18th[6] = { 0, 1, 3, 7, 15, 31 }; //18년도 순위 정보
	int prize_18th[5] = { 512, 256, 128, 64, 32 }; //18년도 상금 정보

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		a_reward = 0;
		b_reward = 0;
		scanf("%d", &a);
		scanf("%d", &b);

		for (int j = 0; j < 6; j++)
		{
			if (a > reward_17th[j] && a <= reward_17th[j + 1])
			{
				a_reward = prize_17th[j];
			}
		}

		for (int j = 0; j < 5; j++)
		{
			if (b > reward_18th[j] && b <= reward_18th[j + 1])
			{
				b_reward = prize_18th[j];
			}
		}
		printf("%d\n", (a_reward + b_reward) * 10000);
	}

	return 0;
}