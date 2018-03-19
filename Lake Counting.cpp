#include<cstdio>
#define max_m 100
#define max_n 100

void Search(int m, int n);

int m, n;
int M, N;
int mm, nn;
char A[max_m][max_n + 1];

void Search(int m, int n) {
	A[m][n] = '.';
	for (int mx = -1; mx <= 1; mx++) {
		for (int ny = -1; ny <= 1; ny++) {
			mm = m + mx;
			nn = n + ny;
			if (mm >= 0 && mm < M && nn >= 0 && nn < N && A[mm][nn] == 'W')
			{
				Search(mm, nn);
			}
		}
	}
}

int main() {
	int sum = 0;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++) {
		scanf("%s", A[i]);

	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == 'W') {
				Search(i, j);
				sum += 1;
			}
		}
	}
	printf("%d", sum);
	return 0;
}





