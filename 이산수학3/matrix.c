#include<stdio.h>

int a[302][302];	//�迭 �ޱ�
int aa[302];		//����??
int bb[302];	//����??

int main() {
	FILE *input_fp, *output_fp;
	if ((input_fp = fopen("matrix.inp", "rt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "matrix.inp");
	}
	if ((output_fp = fopen("matrix.out", "wt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "matrix.out");
	}
	int finally = 0;	//�����Ѱ�+�����Ѱ� ���ֱ�
	int T = 0;	//testcase����
	int num = 0;	//��� num*num�����
	int k = 0;	//��ľȿ� ���� ��
	int count1, count2;	//count1�� 1�� ����, count2�� 1�� �ƴ� ���� ����
	int i, j;	//��� �⺻����
	int s, r;	//ã������ ���� ������ ���� ����
	fscanf(input_fp, "%d\n", &T);
	for (T; T > 0; T--) {
		fscanf(input_fp, "%d\n", &num);
		int op = num*num;
		count1 = 0;
		count2 = 0;
		for (i = 0; i < num; i++) {
			for (j = 0; j < num; j++) {
				fscanf(input_fp, "%d ", &k);
				a[i][j] = k;
			}
		}
		for (i = 0; i < num; i++) {
			for (j = 0; j < num; j++) {
				if (a[i][j] != 1) {
					for (s = 0; s < num; s++) {
						for (r = 0; r < (num - 1); r++) {
							finally = a[s][j] + a[i][r];
							if (a[i][j] == finally && s != i&&r != j) {	//�� ��!!
								break;
							}
						}
						if (a[i][j] == a[s][j] + a[i][r] && s != i&&r != j) {	//���� ���� ���� �ִ� ������ for���� �ߴ��ϱ� ���ؼ� �� ����
							count2++;	//��� count2�� ���⼭ ��
							break;
						}
					}
				}
				else {
					count1++;	//1�϶� count1�� ����
					continue;
				}
			}
		}
		if (op == count1 + count2) {	//ī���͵��� ���� ��İ� ������ ������ 1���
			fprintf(output_fp, "1\n");
		}
		else if (op != count1 + count2) {	//�ٸ��� 0���
			fprintf(output_fp, "0\n");
		}
	}
	fclose(input_fp);
	fclose(output_fp);
}