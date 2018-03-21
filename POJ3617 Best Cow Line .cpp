#include<cstdio>
#include<iostream>


using namespace std;
char A[2010];
char B[2010];
int N;

int main()
{
	int sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf(" %c", &A[i]);//前面的空格用来匹配空白符号 
	}

	int s = 0, t = N - 1;
	int j = 0;
	while (s < t)
	{
		for (int i = 0; s + i <= t - i; i++)
		{
			//printf("%c   %c", A[s + i], A[t - i]);
			if (A[s + i] < A[t - i])
			{
				B[j++] = A[s];
				s++;
				break;
			}
			else if (A[s + i] > A[t - i])
			{
				B[j++] = A[t];
				t--;
				break;
			}
			else if (A[s + i] == A[t - i] && ((s + i) == (t - i) || (s + i + 1) == (t - i)))
			{
				B[j++] = A[t];
				t--;
				break;
			}
		}
	}
	B[j++] = A[s];

	//输出结果

	for (int i = 0; i < N; i++)
	{
		printf("%c", B[i]);
		sum = sum + 1;
		if (sum == 80)
		{
			printf("\n");
			sum = 0;
		}
	}
	return 0;
}