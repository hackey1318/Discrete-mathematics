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
	int e, d;	//�׳� for�� ���� ���� ����
	int k = 0;
	char enter = NULL;	//enter�� �ޱ� ���ؼ�
	int i, j;
	int culcu1 = 0, count = 0;	//culcu1�� ������ ����, count�� ���� �Ѱ��� �������� �󸶳� �þ������ �Ǵ�
	int t;	//for�� ������ ���� ��
	fscanf(input_File, "%d\n", &num);	//test case
	for (t=1; t <= num; t++) {
		fscanf(input_File, "%d\n", &cycle); //�迭�� �󸶳� ����
		for (e=0; e < cycle; e++) {
			fscanf(input_File, "%d%c", &k, &enter); //�׶� �迭�� ���� �� �޴°�
			a[e] = k;
			if (enter == '\n') {
				for (d=0; d < cycle; d++) {
					fscanf(input_File, "%d%c", &k, &enter);
					b[d] = k;
				}
			}
		}
		//�̰� c�迭�̰� b[j]���� j���� c�迭�� ����
		for (i = 0; i < cycle; i++) {
			for (j = 0; j < cycle; j++) {
				if (a[i] == b[j]) {
					c[i] = j;
					break;
				}
			}
		}
		j = 1;
		//���ذ��� �񱳰��� ���ؼ� ī���͸� �÷���
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