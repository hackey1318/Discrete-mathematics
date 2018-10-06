#include<stdio.h>

int main() {
	FILE *input_fp, *output_fp;
	if ((input_fp = fopen("sequence.inp", "rt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "sequence.inp");
	}
	if ((output_fp = fopen("sequence.out", "wt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "sequence.out");
	}
	int testcase = 1;
	int  A = 0, limit = 0;	
	int a = 0;
	while (1) {
		int i = 1;
		fscanf(input_fp, "%d %d\n", &A, &limit);
		a = A;
		if (A == -1 || limit == -1) {
			break;
		}
		if (A == 1) {
			fprintf(output_fp, "Case %d: A = %d, limit = %d, number of terms = %d\n", testcase, a, limit, i);
		}
		else if (A != 1) {
			while (A != 1) {
				if (A <= limit) {
					if (A % 2 == 1) {
						A = 3 * A + 1;
						i++;
						if (A < 0) {
							i = i - 1;
							break;
						}
					}
					else if (A % 2 == 0) {
						A = A / 2;
						i++;
					}
				}
				else if (A > limit) {
					i = i - 1;
					break;
				}
			}
		}
		fprintf(output_fp, "Case %d: A = %d, limit = %d, number of terms = %d\n", testcase, a, limit, i);
		testcase++;
	}
	fclose(input_fp);
	fclose(output_fp);
}

//Case %d: A = %d, limit = %d, number of terms = %d