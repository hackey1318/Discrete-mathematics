#include<stdio.h>
int col[50][50];
int row[50][50];
int k[50][50];
int l[50][50];
int main() {
	FILE *input_fp, *output_fp;
	if ((input_fp = fopen("paper.inp", "rt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "a.inp");
	}
	if ((output_fp = fopen("paper.out", "wt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "a.out");
	}
	int num = 0;
	int m = 0, n = 0;	//n은 세로, m은 가로
	int i = 0, j = 0, o = 0, p = 0, q = 0;
	int a = 0;
	int yes = 0;
	int t = 0;
	fscanf(input_fp, "%d", &num);
	while (num > 0) {
		fscanf(input_fp, "%d %d\n", &n, &m);
		q = (n - 1)*(m - 1);
		yes = 1;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m - 1; j++) {
				fscanf(input_fp, "%d", &a);
				row[i][j] = a;
			}
		}
		for (i = 0; i < n-1; i++) {
			for (j = 0; j < m; j++) {
				fscanf(input_fp, "%d", &a);
				col[i][j] = a;
			}
		}
		for (i = 0; i < m - 1; i++) {
			for (j = 0; j < n - 1; j++) {
				k[j][i] = row[j][i] + row[j + 1][i];
			}
		}
		for (o = 0; o < n - 1; o++) {
			for (p = 0; p < m - 1; p++) {
				l[o][p] = col[o][p] + col[o][p + 1];
			}
		}
		for (i = 0; i < n - 1; i++) {
			for (j = 0; j < m - 1; j++) {
				t = k[i][j] + l[i][j];
				if (t == 1 || t == 3) {
					continue;
				}
				if (t != 1 || t != 3) {
					yes = 0;
					break;
				}
			}
		}
		fprintf(output_fp, "%d ", yes);
		num--;
	}
	fclose(input_fp);
	fclose(output_fp);
}