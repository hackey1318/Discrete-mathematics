#include<stdio.h>

char a[100];

int main() {
	FILE *input_fp, *output_fp;
	if ((input_fp = fopen("mail.inp", "rt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "mail.inp");
	}
	if ((output_fp = fopen("mail.out", "wt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "mail.out");
	}
	int i = 6;
	int b;
	int j = 0;
	int k = 0;
	int num = 0;	//testcase
	int crypto = 0;	//��ȣ����
	char c, d, e, f, g, h;
	int m = 0;
	fscanf(input_fp, "%d\n", &num);
	for (num; num > 0; num--) {
		fscanf(input_fp, "%d\n", &crypto);
		for (crypto; crypto > 0; crypto--) {
			j = crypto*i;
			for (b = 0; b < j; b++) {
				a[b] = fgetc(input_fp);
			}
			b = 0;
			for (b; b < crypto; b++) {
				c = NULL, d = NULL, e = NULL, f = NULL, g = NULL, h = NULL;
				m = b*i;
				c = a[m];
				d = a[m + 1];
				e = a[m + 2];
				f = a[m + 3];
				g = a[m + 4];
				h = a[m + 5];
				if ((c == '0' && d == '0' && e == '0' && f == '0' && g == '0' && h == '0') || (c == '1' && d == '0' && e == '0' && f == '0' && g == '0' && h == '0') || (c == '0' && d == '1' && e == '0' && f == '0' && g == '0' && h == '0') || (c == '0' && d == '0' && e == '1' && f == '0' && g == '0' && h == '0') || (c == '0' && d == '0' && e == '0' && f == '1' && g == '0' && h == '0') || (c == '0' && d == '0' && e == '0' && f == '0' && g == '1' && h == '0') || (c == '0' && d == '0' && e == '0' && f == '0' && g == '0' && h == '1')) {
					fprintf(output_fp, "A");
				}
				else if ((c == '0' && d == '0' && e == '1' && f == '1' && g == '1' && h == '1') || (c == '1' && d == '0' && e == '1' && f == '1' && g == '1' && h == '1') || (c == '0' && d == '1' && e == '1' && f == '1' && g == '1' && h == '1') || (c == '0' && d == '0' && e == '0' && f == '1' && g == '1' && h == '1') || (c == '0' && d == '0' && e == '1' && f == '0' && g == '1' && h == '1') || (c == '0' && d == '0' && e == '1' && f == '1' && g == '0' && h == '1') || (c == '0' && d == '0' && e == '1' && f == '1' && g == '1' && h == '0')) {
					fprintf(output_fp, "B");
				}
				else if ((c == '0' && d == '1' && e == '0' && f == '0' && g == '1' && h == '1')|| (c == '1' && d == '1' && e == '0' && f == '0' && g == '1' && h == '1')|| (c == '0' && d == '0' && e == '0' && f == '0' && g == '1' && h == '1')|| (c == '0' && d == '1' && e == '1' && f == '0' && g == '1' && h == '1')|| (c == '0' && d == '1' && e == '0' && f == '1' && g == '1' && h == '1')|| (c == '0' && d == '1' && e == '0' && f == '0' && g == '0' && h == '1') || (c == '0' && d == '1' && e == '0' && f == '0' && g == '1' && h == '0')) {
					fprintf(output_fp, "C");
				}
				else if ((c == '0' && d == '1' && e == '1' && f == '1' && g == '0' && h == '0')||(c == '1' && d == '1' && e == '1' && f == '1' && g == '0' && h == '0')|| (c == '0' && d == '0' && e == '1' && f == '1' && g == '0' && h == '0')|| (c == '0' && d == '1' && e == '0' && f == '1' && g == '0' && h == '0') || (c == '0' && d == '1' && e == '1' && f == '0' && g == '0' && h == '0') || (c == '0' && d == '1' && e == '1' && f == '1' && g == '1' && h == '0') || (c == '0' && d == '1' && e == '1' && f == '1' && g == '0' && h == '1')) {
					fprintf(output_fp, "D");
				}
				else if ((c == '1' && d == '0' && e == '0' && f == '1' && g == '1' && h == '0')|| (c == '0' && d == '0' && e == '0' && f == '1' && g == '1' && h == '0') || (c == '1' && d == '1' && e == '0' && f == '1' && g == '1' && h == '0') || (c == '1' && d == '0' && e == '1' && f == '1' && g == '1' && h == '0') || (c == '1' && d == '0' && e == '0' && f == '0' && g == '1' && h == '0') || (c == '1' && d == '0' && e == '0' && f == '1' && g == '0' && h == '0') || (c == '1' && d == '0' && e == '0' && f == '1' && g == '1' && h == '1')) {
					fprintf(output_fp, "E");
				}
				else if ((c == '1' && d == '0' && e == '1' && f == '0' && g == '0' && h == '1') || (c == '0' && d == '0' && e == '1' && f == '0' && g == '0' && h == '1') || (c == '1' && d == '1' && e == '1' && f == '0' && g == '0' && h == '1') || (c == '1' && d == '0' && e == '0' && f == '0' && g == '0' && h == '1') || (c == '1' && d == '0' && e == '1' && f == '1' && g == '0' && h == '1') || (c == '1' && d == '0' && e == '1' && f == '0' && g == '1' && h == '1') || (c == '1' && d == '0' && e == '1' && f == '0' && g == '0' && h == '0')) {
					fprintf(output_fp, "F");
				}
				else if ((c == '1' && d == '1' && e == '0' && f == '1' && g == '0' && h == '1') || (c == '0' && d == '1' && e == '0' && f == '1' && g == '0' && h == '1') || (c == '1' && d == '0' && e == '0' && f == '1' && g == '0' && h == '1') || (c == '1' && d == '1' && e == '1' && f == '1' && g == '0' && h == '1') || (c == '1' && d == '1' && e == '0' && f == '0' && g == '0' && h == '1') || (c == '1' && d == '1' && e == '0' && f == '1' && g == '1' && h == '1') || (c == '1' && d == '1' && e == '0' && f == '1' && g == '0' && h == '0')) {
					fprintf(output_fp, "G");
				}
				else if ((c == '1' && d == '1' && e == '1' && f == '0' && g == '1' && h == '0')||(c == '0' && d == '1' && e == '1' && f == '0' && g == '1' && h == '0')||(c == '1' && d == '0' && e == '1' && f == '0' && g == '1' && h == '0')||(c == '1' && d == '1' && e == '0' && f == '0' && g == '1' && h == '0')||(c == '1' && d == '1' && e == '1' && f == '1' && g == '1' && h == '0')||(c == '1' && d == '1' && e == '1' && f == '0' && g == '0' && h == '0')||(c == '1' && d == '1' && e == '1' && f == '0' && g == '1' && h == '1')) {
					fprintf(output_fp, "H");
				}
				else {
					fprintf(output_fp, "X");
				}
			}
			if (b == crypto) {
				break;
			}
		}
		fprintf(output_fp, "\n");
	}
	fclose(input_fp);
	fclose(output_fp);
}