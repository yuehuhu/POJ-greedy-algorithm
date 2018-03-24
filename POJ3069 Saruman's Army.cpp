#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
int A[1000];
int N, R;


void solve()
{
	int sum = 0;
	int i = 0;
	sort(A, A + N);
	while (i < N)
	{
		int st = A[i++];
		while (i < N && st + R>= A[i])
		{
			i++;
		}
		int en = A[i-1];
		while (i < N && en + R >= A[i])
		{
			i++;
		}
		sum++;
	}
	printf("%d\n", sum);
}

int main()
{
	while (true)
	{
		scanf("%d %d", &R, &N);
		if (R != -1 && N != -1)
		{
			for (int i = 0; i < N; i++)
			{
				scanf("%d", &A[i]);
			}
			solve();
		}
		else
			break;
	}
	return 0;
}