#include<cstdio>
#define N_max 1000000
int L, n;
int x[N_max];
int total_min, total_max;
int total_num;

int Min(int a, int b)
{
	return a < b ? a : b;
}

int Max(int a, int b)
{
	return a > b ? a : b;
}


int main()
{
	scanf("%d", &total_num);

	while (total_num--) {
		scanf("%d %d", &L, &n);
		total_min = -1;
		total_max = -1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x[i]);
			total_min = Max(total_min, Min(x[i], L - x[i]));
			total_max = Max(total_max, Max(x[i], L - x[i]));
		}
		printf("%d %d\n", total_min, total_max);
	}
	getchar();
	getchar();
	return 0;
}