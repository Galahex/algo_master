/*
baekjoon algorithm
Question number: 15954
https://www.acmicpc.net/problem/15954
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	int N; //인형의 개수
	int K; //K개이상 연속된 위치에 있는 인형 선택

	long long prefer[501]; //일렬로 나열된 인형의 선호도
	long long sum = 0;
	long long cnt = 0;
	long double mean; //평균
	long double variance; //분산
	long double std_deviation; //표준편차
	long double min = 2147483647;

	scanf("%d", &N);
	scanf("%d", &K);

	for (int i = 1; i <= N; i++) scanf("%lld", &prefer[i]);

	for (int i = 1; i <= (N - K + 1); i++)
	{
		sum = 0;
		cnt = 0;
		for (int j = i; j <= N; j++)
		{
			sum += prefer[j];
			cnt += 1;
			if (cnt < K) continue;
			mean = (long double)sum / cnt;
			variance = 0;
			std_deviation = 0;
			for (int k = i; k <= j; k++)
			{
				variance += pow((prefer[k] - mean), 2);
			}
			variance /= cnt;
			std_deviation = sqrt(variance);
			if (min > std_deviation) min = std_deviation;
		}
	}

	printf("%0.11Lf\n", min);

	return 0;
}