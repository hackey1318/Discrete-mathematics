#include<stdio.h>
int a[10000][10000];

int add(int k[10000][10000], int i, int j) {
	if (k[i][j] == -1&& k[i + 1][j]!=-1&& k[i + 1][j+1]!=-1) {
		k[i][j] = k[i + 1][j] + k[i + 1][j + 1];
	}
	else if (k[i][j] != -1 && k[i + 1][j] == -1 && k[i + 1][j + 1] != -1) {
		k[i + 1][j] = k[i][j] - k[i + 1][j + 1];
	}
	else if (k[i][j] != -1 && k[i + 1][j] != -1 && k[i + 1][j + 1] == -1) {
		k[i + 1][j + 1] = k[i][j] - k[i + 1][j];
	}
	else if ((k[i][j] == -1 && k[i + 1][j] == -1 && k[i + 1][j + 1] != -1) || (k[i][j] == -1 && k[i + 1][j] != -1 && k[i + 1][j + 1] == -1) || (k[i][j] != -1 && k[i + 1][j] == -1 && k[i + 1][j + 1] == -1) || k[i][j] == -1 && k[i + 1][j] == -1 && k[i + 1][j + 1] == -1) {
		k[i][j] = -1;
	}
	return 0;
}

int main() {
	FILE *input_fp, *output_fp;
	if ((input_fp = fopen("C:\\Users\\영민\\Desktop\\이산수학\\1.inp", "rt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "1.inp");
	}
	if ((output_fp = fopen("C:\\Users\\영민\\Desktop\\이산수학\\1.out", "wt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "1.out");
	}
	int testcase = 0;
	int treenode = 0;
	int k = 0;
	int i = 0, j = 0, l = 0;
	fscanf(input_fp, "%d\n", &testcase);
	for (l; l < testcase; l++) {
		fscanf(input_fp, "%d\n", &treenode);
		for (i = 0; i < treenode; i++) {
			for (j = 0; j <= i; j++) {
				fscanf(input_fp, "%d ", &k);
				a[i][j] = k;
			}
		}
		for (i = 0; i < treenode; i++) {
			for (j = 0; j <= i; j++) {
				add(a, i, j);
				fprintf(output_fp, "%d ", a[i][j]);
			}
			fprintf(output_fp, "\n");
		}
	}
	fclose(input_fp);
	fclose(output_fp);
}