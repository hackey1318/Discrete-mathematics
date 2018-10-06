#include<stdio.h>

int a[302][302];	//배열 받기
int aa[302];		//가로??
int bb[302];	//세로??

int main() {
	FILE *input_fp, *output_fp;
	if ((input_fp = fopen("matrix.inp", "rt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "matrix.inp");
	}
	if ((output_fp = fopen("matrix.out", "wt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "matrix.out");
	}
	int finally = 0;	//가로한개+세로한개 값넣기
	int T = 0;	//testcase개수
	int num = 0;	//행렬 num*num만들기
	int k = 0;	//행렬안에 넣을 값
	int count1, count2;	//count1은 1의 개수, count2는 1이 아닌 것의 개수
	int i, j;	//행렬 기본변수
	int s, r;	//찾으려는 것을 돌리기 위한 변수
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
							if (a[i][j] == finally && s != i&&r != j) {	//값 비교!!
								break;
							}
						}
						if (a[i][j] == a[s][j] + a[i][r] && s != i&&r != j) {	//위랑 같은 것이 있는 이유는 for문을 중단하기 위해서 해 놓음
							count2++;	//대신 count2는 여기서 함
							break;
						}
					}
				}
				else {
					count1++;	//1일때 count1을 증가
					continue;
				}
			}
		}
		if (op == count1 + count2) {	//카운터들의 합이 행렬값 개수와 같으면 1출력
			fprintf(output_fp, "1\n");
		}
		else if (op != count1 + count2) {	//다르면 0출력
			fprintf(output_fp, "0\n");
		}
	}
	fclose(input_fp);
	fclose(output_fp);
}