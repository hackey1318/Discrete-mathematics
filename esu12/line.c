#include<stdio.h>
#include<math.h>
int main() {
	FILE *input_fp, *output_fp;
	if ((input_fp = fopen("line.inp", "rt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "line.inp");
	}
	if ((output_fp = fopen("line.out", "wt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "line.out");
	}
	int num = 0;
	int q = 0;
	int re = 0;
	int Q = 0;
	int A = 0;
	int a = 0, b = 1000000000;
	int a1 = 0, b1 = 0;
	int k = 0;
	int t1 = 0, t2 = 0;
	double P = 0;
	double T = 0;
	int G = 0, s = 0;
	fscanf(input_fp, "%d\n", &num);
	while (num>0) {
		re = 0;
		a = 0, b = 1000000000, a1 = 0, b1 = 0, t1 = 0, k = 0;
		fscanf(input_fp, "%d\n", &q);
		while (q > 0) {
			fscanf(input_fp, "%d %d\n", &Q, &A);
			re++;
			P = Q;
			T = A;
			t2 = 1;
			if (A != 1) {
				t1 = ceil((T - 1)*T / 2);
				G = A - 2;
				if (G != 0) {
					for (s = 1; s <= G; s++) {
						t2 = t2 + s;
					}
				}
				a1 =ceil((P - t1) / T);
				b1 = (P - t2) / (T - 1);
				if (a < a1) {
					a = a1;
				}
				if (b > b1) {
					b = b1;
				}
				if (a == b) {
					k = a;
					q--;
					while (q > 0) {
						fscanf(input_fp, "%d %d\n", &Q, &A);
						q--;
					}
					break;
				}
			}
			else if (A == 1) {
				if (a < A) {
					a = Q;
				}
				if (a == b) {
					k = a;
					while (q > 0) {
						fscanf(input_fp, "%d %d\n", &Q, &A);
						q--;
					}
					break;
				}
			}
			q--;
		}
		if (a == b) {
			fprintf(output_fp, "%d %d\n", re, k);
		}
		else {
			fprintf(output_fp, "-1\n");
		}
		num--;
	}
	fclose(input_fp);
	fclose(output_fp);
}