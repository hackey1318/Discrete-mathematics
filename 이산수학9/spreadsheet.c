#include<stdio.h>
#include<math.h>
char a[25];
char b[25];
char c[25];
char d[25];

int f(int a, int b) {
	if (b == 1) {
		return a;
	}
	return a*f(a, b - 1);
}

int main() {
	FILE *input_fp, *output_fp;
	if ((input_fp = fopen("spreadsheet1.inp", "rt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "spreadsheet.inp");
	}
	if ((output_fp = fopen("spreadsheet.out", "wt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "spreadsheet.out");
	}
	int num = 0;
	int i = 0, j = 0;
	int enter = 0;
	int col = 0, row = 0;
	int o = 10, p = 26;
	int count1 = 0, count2 = 0;
	int div = 0, remain = 0;
	int startcase = 0;
	fscanf(input_fp, "%d\n", &num);
	while (num > 0) {
		count1 = 0; count2 = 0;
		col = 0, row = 0;
		for (i = 0; i < 20; i++) {
			fscanf(input_fp, "%c", &a[i]);
			if (a[i] == '\n') {
				enter = i;
				break;
			}
		}
		if ('A' <= a[0] && a[0] <= 'Z' && a[0]!='R') {
			for (i = 0; i < enter; i++) {
				if ('A' <= a[i] && a[i] <= 'Z') {
					b[i] = a[i];
					count1++;
				}
				else if ('0' <= a[i] && a[i] <= '9') {
					for (j = 0; j < i; j++) {
						if (i - (j + 1) == 0) {
							col = col + ((int)b[j] - 64);
						}
						else if (i - (j + 1) != 0) {
							col = col + ((int)b[j] - 64)*f(p, i - (j + 1));
						}
					}
					break;
				}
			}
			for (i; i < enter; i++) {
				c[enter - (i + 1)] = a[i];
				count2++;
			}
			for (count2 = count2 - 1; count2 >= 0; count2--) {
				if (count2 != 0) {
					row = row + ((int)c[count2] - 48)*f(o, count2);
				}
				else if (count2 == 0) {
					row = row + ((int)c[count2] - 48);
				}
			}
			fprintf(output_fp, "R%dC%d", row, col);
		}
		else if (a[0] == 'R' && 'A' <= a[1] && a[1] <= 'Z') {
			for (i = 0; i < enter; i++) {
				if ('A' <= a[i] && a[i] <= 'Z') {
					b[i] = a[i];
					count1++;
				}
				else if ('0' <= a[i] && a[i] <= '9') {
					for (j = 0; j < i; j++) {
						if (i - (j + 1) == 0) {
							col = col + ((int)b[j] - 64);
						}
						else if (i - (j + 1) != 0) {
							col = col + ((int)b[j] - 64)*f(p, i - (j + 1));
						}
					}
					break;
				}
			}
			for (i; i < enter; i++) {
				c[enter - (i + 1)] = a[i];
				count2++;
			}
			for (count2 = count2 - 1; count2 >= 0; count2--) {
				if (count2 != 0) {
					row = row + ((int)c[count2] - 48)*f(o, count2);
				}
				else if (count2 == 0) {
					row = row + ((int)c[count2] - 48);
				}
			}
			fprintf(output_fp, "R%dC%d", row, col);
		}
		else if (a[0] == 'R' && '0' <= a[1] && a[1] <= '9') {
			for (i = 1; i < enter + 1; i++) {
				if ('0' <= a[i] && a[i] <= '9') {
					c[i - 1] = a[i];
					count1++;
				}
				else if (a[i] == 'C') {
					startcase = 1;
					break;
				}
				else if (a[i] == '\n') {
					startcase = 0;
					break;
				}
			}
			switch (startcase)
			{
			case 0:
				fprintf(output_fp, "R");
				for (j = 0; j < count1; j++) {
					fprintf(output_fp, "%c", c[j]);
				}
				fprintf(output_fp, "C18");
				break;
			case 1:
				if (a[i] == 'C') {
					for (j = 0; j < count1; j++) {
						if (count1 - j - 1 == 0) {
							row = row + ((int)c[j] - 48);
							break;
						}
						else if (count1 - j - 1 != 0) {
							row = row + ((int)c[j] - 48)*f(o, count1 - j - 1);
						}
					}
				}
				for (i = i + 1; i < enter; i++) {
					c[enter - (i + 1)] = a[i];
					count2++;
				}
				for (count2 = count2 - 1; count2 >= 0; count2--) {
					if (count2 != 0) {
						col = col + (((int)c[count2] - 48) * f(o, count2));
					}
					else if (count2 == 0) {
						col = col + ((int)c[count2] - 48);
						break;
					}
				}
				while (1) {
					if (col <= 26) {
						div = col / 26;
						remain = col % 26;
						count1 = 0;
						if (remain == 0) {
							div = div - 1;
							remain = 26;
						}
						d[0] = remain + 64;
						if (div != 0) {
							d[1] = div + 64;
						}
						break;
					}
					else {
						div = col / 26;
						remain = col % 26;
						count1 = 1;
						for (i = 0; i < 5; i++) {
							if (remain == 0) {
								div = div - 1;
								remain = 26;
							}
							count1++;
							if (div >= 27) {
								d[i] = remain + 64;
								remain = div % 26;
								div = div / 26;
							}
							else if (div <= 26) {
								d[i] = remain + 64;
								d[i + 1] = div + 64;
								break;
							}
						}
						break;
					}
				}
				for (count1; count1 >= 0; count1--) {
					fprintf(output_fp, "%c", d[count1]);
				}
				fprintf(output_fp, "%d", row);
			}
		}
		for (i = 0; i < 20; i++) {
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
			d[i] = 0;
		}
		if (num - 1 != 0) {
			fprintf(output_fp, "\n");
		}
		num--;
	}
	fclose(input_fp);
	fclose(output_fp);
}