#include<stdio.h>


void Total(FILE *T, FILE *P, int t, char c1, char c2, int k) {
	fscanf(T, "%d\n", &t);
	fscanf(T, "%c", &c1);
	t -= 1;
	while (t>0) {
		fscanf(T, "%c", &c2);
		if (c1 == c2) {
			k += 5;
			c1 = 0;
			c1 = c2;
			c2 = 0;
			t--;
		}
		else if (c1 != c2) {
			k += 10;
			c1 = 0;
			c1 = c2;
			c2 = 0;
			t--;
		}
		if (t == 0) {
			fprintf(P, "%d", k);
			break;
		}
	}
}

int main() {
	FILE *input_fp, *output_fp;
	if ((input_fp = fopen("dish.inp", "rt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "dish.inp");
	}
	if ((output_fp = fopen("dish.out", "wt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "dish.out");
	}
	int a = 0, e=0;
	int total=10;
	char b=NULL, c=NULL;
	fscanf(input_fp, "%d", &a);
	for (a;a>0; a--) {
		Total(input_fp, output_fp, e, b, c, total);
		fprintf(output_fp, "\n");
	}
	fclose(input_fp);
	fclose(output_fp);
}