#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
long long A[20000];
int N;

int main()
{
	long long sum=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%I64d", &A[i]);
	}

	while (N > 1)
	{
		int min1 = 0, min2 = 1;           //min1最小，min2次小
		if (A[min1] > A[min2])
		{
			int temp = min1;
			min1 = min2;
			min2 = temp;
		}
		for (int i = 2; i < N; i++)
		{
			if (A[i] < A[min2])
			{
				min2 = i;
				if (A[min2] < A[min1])
				{
					int temp = min1;
					min1 = min2;
					min2 = temp;
				}
			}
		}
		int t = A[min1] + A[min2];
		sum = sum + t;
		A[min1] = t;
		A[min2] = A[N - 1];
		N--;
	}
	printf("%I64d", sum);
	return 0;
}