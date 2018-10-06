#include<stdio.h>
int brr[6];
int crr[6];
int drr[10000][6];
int bo(int a, int b, int c) {
	if (a == 6 || b == 6) {
		if (a == 5 || b == 5) {
			c = 4;
		}
		else {
			c = 5;
		}
	}
	else {
		c = 6;
	}
	return c;
}
int main() {
	FILE *input_fp, *output_fp;
	if ((input_fp = fopen("dice.inp", "rt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "dice.inp");
	}
	if ((output_fp = fopen("dice.out", "wt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "dice.out");
	}
	int num = 0;
	int i = 0, j = 0, o = 0;
	int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0;
	int top = 0;
	int bottom = 0;
	int k = 0;
	int p = 0;
	int T = 0;
	int total = 0;
	fscanf(input_fp, "%d", &num);
	fscanf(input_fp, "%d %d %d %d %d %d\n", &A, &B, &C, &D, &E, &F);
	crr[0] = A, crr[1] = B, crr[2] = C, crr[3] = D, crr[4] = E, crr[5] = F;
	for (i = 0; i < num - 1; i++) {
		for (j = 0; j < 6; j++) {
			fscanf(input_fp, "%d ", &T);
			drr[i][j] = T;
		}
	}
	for (i = 0; i < 6; i++) {
		p = num - 1;
		bottom = crr[i];
		while (1) {
			if (bottom == A) {
				top = F;
				brr[0] = bo(top, bottom, k);
				for (j = 0; j < p;j++) {
					A = drr[j][0], B = drr[j][1], C = drr[j][2], D = drr[j][3], E = drr[j][4], F = drr[j][5];
					bottom = top;
					if (bottom == A) {
						top = F;
						brr[0] = brr[0] + bo(top, bottom, k);
					}
					else if (bottom == B) {
						top = D;
						brr[0] = brr[0] + bo(top, bottom, k);
					}
					else if (bottom == C) {
						top = E;
						brr[0] = brr[0] + bo(top, bottom, k);
					}
					else if (bottom == D) {
						top = B;
						brr[0] = brr[0] + bo(top, bottom, k);
					}
					else if (bottom == E) {
						top = C;
						brr[0] = brr[0] + bo(top, bottom, k);
					}
					else if (bottom == F) {
						top = A;
						brr[0] = brr[0] + bo(top, bottom, k);
					}
				}
			}
			else if (bottom == B) {
				top = D;
				brr[1] = bo(top, bottom, k);
				for (j = 0; j < p; j++) {
					A = drr[j][0], B = drr[j][1], C = drr[j][2], D = drr[j][3], E = drr[j][4], F = drr[j][5];
					bottom = top;
					if (bottom == A) {
						top = F;
						brr[1] = brr[1] + bo(top, bottom, k);
					}
					else if (bottom == B) {
						top = D;
						brr[1] = brr[1] + bo(top, bottom, k);
					}
					else if (bottom == C) {
						top = E;
						brr[1] = brr[1] + bo(top, bottom, k);
					}
					else if (bottom == D) {
						top = B;
						brr[1] = brr[1] + bo(top, bottom, k);
					}
					else if (bottom == E) {
						top = C;
						brr[1] = brr[1] + bo(top, bottom, k);
					}
					else if (bottom == F) {
						top = A;
						brr[1] = brr[1] + bo(top, bottom, k);
					}
				}
			}
			else if (bottom == C) {
				top = E;
				brr[2] = bo(top, bottom, k);
				for (j = 0; j < p; j++) {
					A = drr[j][0], B = drr[j][1], C = drr[j][2], D = drr[j][3], E = drr[j][4], F = drr[j][5];
					bottom = top;
					if (bottom == A) {
						top = F;
						brr[2] = brr[2] + bo(top, bottom, k);
					}
					else if (bottom == B) {
						top = D;
						brr[2] = brr[2] + bo(top, bottom, k);
					}
					else if (bottom == C) {
						top = E;
						brr[2] = brr[2] + bo(top, bottom, k);
					}
					else if (bottom == D) {
						top = B;
						brr[2] = brr[2] + bo(top, bottom, k);
					}
					else if (bottom == E) {
						top = C;
						brr[2] = brr[2] + bo(top, bottom, k);
					}
					else if (bottom == F) {
						top = A;
						brr[2] = brr[2] + bo(top, bottom, k);
					}
				}
			}
			else if (bottom == D) {
				top = B;
				brr[3] = bo(top, bottom, k);
				for (j = 0; j < p; j++) {
					A = drr[j][0], B = drr[j][1], C = drr[j][2], D = drr[j][3], E = drr[j][4], F = drr[j][5];
					bottom = top;
					if (bottom == A) {
						top = F;
						brr[3] = brr[3] + bo(top, bottom, k);
					}
					else if (bottom == B) {
						top = D;
						brr[3] = brr[3] + bo(top, bottom, k);
					}
					else if (bottom == C) {
						top = E;
						brr[3] = brr[3] + bo(top, bottom, k);
					}
					else if (bottom == D) {
						top = B;
						brr[3] = brr[3] + bo(top, bottom, k);
					}
					else if (bottom == E) {
						top = C;
						brr[3] = brr[3] + bo(top, bottom, k);
					}
					else if (bottom == F) {
						top = A;
						brr[3] = brr[3] + bo(top, bottom, k);
					}
				}
			}
			else if (bottom == E) {
				top = C;
				brr[4] = bo(top, bottom, k);
				for (j = 0; j < p; j++) {
					A = drr[j][0], B = drr[j][1], C = drr[j][2], D = drr[j][3], E = drr[j][4], F = drr[j][5];
					bottom = top;
					if (bottom == A) {
						top = F;
						brr[4] = brr[4] + bo(top, bottom, k);
					}
					else if (bottom == B) {
						top = D;
						brr[4] = brr[4] + bo(top, bottom, k);
					}
					else if (bottom == C) {
						top = E;
						brr[4] = brr[4] + bo(top, bottom, k);
					}
					else if (bottom == D) {
						top = B;
						brr[4] = brr[4] + bo(top, bottom, k);
					}
					else if (bottom == E) {
						top = C;
						brr[4] = brr[4] + bo(top, bottom, k);
					}
					else if (bottom == F) {
						top = A;
						brr[4] = brr[4] + bo(top, bottom, k);
					}
				}
			}
			else if (bottom == F) {
				top = A;
				brr[5] = bo(top, bottom, k);
				for (j = 0; j < p; j++) {
					A = drr[j][0], B = drr[j][1], C = drr[j][2], D = drr[j][3], E = drr[j][4], F = drr[j][5];
					bottom = top;
					if (bottom == A) {
						top = F;
						brr[5] = brr[5] + bo(top, bottom, k);
					}
					else if (bottom == B) {
						top = D;
						brr[5] = brr[5] + bo(top, bottom, k);
					}
					else if (bottom == C) {
						top = E;
						brr[5] = brr[5] + bo(top, bottom, k);
					}
					else if (bottom == D) {
						top = B;
						brr[5] = brr[5] + bo(top, bottom, k);
					}
					else if (bottom == E) {
						top = C;
						brr[5] = brr[5] + bo(top, bottom, k);
					}
					else if (bottom == F) {
						top = A;
						brr[5] = brr[5] + bo(top, bottom, k);
					}
				}
			}
			A = crr[0], B = crr[1], C = crr[2], D = crr[3], E = crr[4], F = crr[5];
			break;
		}
	}
	for (i = 0; i < 5; i++) {
		if (brr[i] < brr[i + 1]) {
			total = brr[i + 1];
		}
		else {
			brr[i + 1] = brr[i];
			total = brr[i + 1];
		}
	}
	fprintf(output_fp, "%d", total);
	fclose(input_fp);
	fclose(output_fp);
}