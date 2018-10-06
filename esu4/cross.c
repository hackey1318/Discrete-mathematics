#include<stdio.h>

int a[10000], b[10000], c[10000];

int main() {
	FILE *input_File, *output_File;
	if ((input_File = fopen("cross.inp", "rt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "cross.inp");
	}
	if ((output_File = fopen("cross.out", "wt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "cross.out");
	}
	int num = 0;
	int cycle = 0;
	int e, d;	//그냥 for문 쓰기 위한 값들
	int k = 0;
	char enter = NULL;	//enter을 받기 위해서
	int i, j;
	int culcu1 = 0, count = 0;	//culcu1는 교차점 개수, count는 숫자 한개당 교차점이 얼마나 늘어나는지를 판단
	int t;	//for문 돌리기 위한 값
	fscanf(input_File, "%d\n", &num);	//test case
	for (t=1; t <= num; t++) {
		fscanf(input_File, "%d\n", &cycle); //배열에 얼마나 들어갈지
		for (e=0; e < cycle; e++) {
			fscanf(input_File, "%d%c", &k, &enter); //그때 배열에 들어가는 걸 받는거
			a[e] = k;
			if (enter == '\n') {
				for (d=0; d < cycle; d++) {
					fscanf(input_File, "%d%c", &k, &enter);
					b[d] = k;
				}
			}
		}
		//이게 c배열이고 b[j]에서 j값을 c배열에 넣음
		for (i = 0; i < cycle; i++) {
			for (j = 0; j < cycle; j++) {
				if (a[i] == b[j]) {
					c[i] = j;
					break;
				}
			}
		}
		j = 1;
		//기준값과 비교값을 비교해서 카운터를 올려줌
		for (i=1; i < cycle; i++) {
			for (j; j < cycle; j++) {
				if (c[i - j]>c[i]) {
					count++;
					culcu1 = culcu1 + count;
					count = 0;
				}
				if (i - j == 0) {
					i++;
					j = 0;
				}
				if (i == cycle) {
					break;
				}
			}
		}
		fprintf(output_File, "Case %d: %d\n", t, culcu1);
		culcu1 = 0;
	}
	fclose(input_File);
	fclose(output_File);
}