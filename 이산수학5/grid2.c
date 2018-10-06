#include<stdio.h>

int main() {
	FILE *input_fp, *output_fp;
	if ((input_fp = fopen("grid2.inp", "rt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "grid2.inp");
	}
	if ((output_fp = fopen("grid2.out", "wt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "grid2.out");
	}
	int num = 0;	//testcase
	int row = 0, col = 0;	//row는 세로, col은 가로
	int type = 0, startpoint = 0, movement = 0;	//타입, 스타트지점, 이동거리
	int i;
	int initial1;
	int transfer;
	int maxrow = 0, maxcol = 0;
	fscanf(input_fp, "%d\n", &num);
	for (num; num > 0; num--) {
		fscanf(input_fp, "%d %d %d %d %d\n", &row, &col, &type, &startpoint, &movement);
		maxcol = col, maxrow = row;
		if (type == 3) {
			switch (startpoint)
			{
			case 1:
				initial1 = 0;
				transfer = 1;
				while (maxcol >= 0 && maxrow >= 0) {
					if (movement != 0) {
						for (i = 0; i < maxcol; i++) {
							initial1 = initial1 + transfer;
							movement--;
							if (movement == 0) {
								break;
							}
						}
					}
					maxcol = maxcol - 1;
					maxrow = maxrow - 1;
					if (movement != 0) {
						for (i = 0; i < maxrow; i++) {
							initial1 = initial1 + (col*transfer);
							movement--;
							if (movement == 0) {
								break;
							}
						}
						transfer *= -1;
					}
					else if (movement == 0) {
						fprintf(output_fp, "%d\n", initial1);
						break;
					}
				}
				break;
			case 2:
				initial1 = 0;
				transfer = 1;
				while (maxcol >= 0 && maxrow >= 0) {
					if (movement != 0) {
						for (i = 0; i < maxrow; i++) {
							initial1 = initial1 + (col*transfer);
							movement--;
							if (movement == 0) {
								break;
							}
						}
					}
					maxrow = maxrow - 1;
					maxcol = maxcol - 1;
					transfer *= -1;
					if (movement != 0) {
						for (i = 0; i < maxcol; i++) {
							initial1 = initial1 + transfer;
							movement--;
							if (movement == 0) {
								break;
							}
						}
					}
					else if (movement == 0) {
						fprintf(output_fp, "%d\n", initial1);
						break;
					}
				}
				break;
			case 3:
				initial1 = (col*row) + 1;
				transfer = -1;
				while (maxcol >= 0 && maxrow >= 0) {
					if (movement != 0) {
						for (i = 0; i < maxcol; i++) {
							initial1 = initial1 + transfer;
							movement--;
							if (movement == 0) {
								break;
							}
						}
					}
					maxrow = maxrow - 1;
					maxcol = maxcol - 1;
					if (movement != 0) {
						for (i = 0; i < maxrow; i++) {
							initial1 = initial1 + (col*transfer);
							movement--;
							if (movement == 0) {
								break;
							}
						}
						transfer *= -1;
					}
					else if (movement == 0) {
						fprintf(output_fp, "%d\n", initial1);
						break;
					}
				}
				break;
			case 4:
				initial1 = (col*row) + 1;
				transfer = -1;
				while (maxcol >= 0 && maxrow >= 0) {
					if (movement != 0) {
						for (i = 0; i < maxrow; i++) {
							initial1 = initial1 +(col* transfer);
							movement--;
							if (movement == 0) {
								break;
							}
						}
					}
					maxrow = maxrow - 1;
					maxcol = maxcol - 1;
					transfer *= -1;
					if (movement != 0) {
						for (i = 0; i < maxcol; i++) {
							initial1 = initial1 + transfer;
							movement--;
							if (movement == 0) {
								break;
							}
						}
					}
					else if (movement == 0) {
						fprintf(output_fp, "%d\n", initial1);
						break;
					}
				}
				break;
			}
		}
		else if (type == 4) {
			switch (startpoint)
			{
			case 1:
				initial1 = 1 - col;
				transfer = 1;
				while (maxcol >= 0 && maxrow >= 0) {
					if (movement != 0) {
						for (i = 0; i < maxrow; i++) {
							initial1 = initial1 + (col*transfer);
							movement--;
							if (movement == 0) {
								break;
							}
						}
					}
					maxrow = maxrow - 1;
					maxcol = maxcol - 1;
					if (movement != 0) {
						for (i = 0; i < maxcol; i++) {
							initial1 = initial1 + transfer;
							movement--;
							if (movement == 0) {
								break;
							}
						}
						transfer *= -1;
					}
					else if (movement == 0) {
						fprintf(output_fp, "%d\n", initial1);
						break;
					}
				}
				break;
			case 2:
				initial1 = col + 1;
				transfer = -1;
				while (maxcol >= 0 && maxrow >= 0) {
					if (movement != 0) {
						for (i = 0; i < maxcol; i++) {
							initial1 = initial1 + transfer;
							movement--;
							if (movement == 0) {
								break;
							}
						}
					}
					maxrow = maxrow - 1;
					maxcol = maxcol - 1;
					transfer *= -1;
					if (movement != 0) {
						for (i = 0; i < maxrow; i++) {
							initial1 = initial1 + (col*transfer);
							movement--;
							if (movement == 0) {
								break;
							}
						}
					}
					else if (movement == 0) {
						fprintf(output_fp, "%d\n", initial1);
						break;
					}
				}
				break;
			case 3:
				initial1 = (col*row) + col;
				transfer = -1;
				while (maxcol >= 0 && maxrow >= 0) {
					if (movement != 0) {
						for (i = 0; i < maxrow; i++) {
							initial1 = initial1 + (col*transfer);
							movement--;
							if (movement == 0) {
								break;
							}
						}
					}
					maxrow = maxrow - 1;
					maxcol = maxcol - 1;
					if (movement != 0) {
						for (i = 0; i < maxcol; i++) {
							initial1 = initial1 + transfer;
							movement--;
							if (movement == 0) {
								break;
							}
						}
						transfer *= -1;
					}
					else if (movement == 0) {
						fprintf(output_fp, "%d\n", initial1);
						break;
					}
				}
				break;
			case 4:
				initial1 = (col*row) - (col - 1) - 1;
				transfer = 1;
				while (maxcol >= 0 && maxrow >= 0) {
					if (movement != 0) {
						for (i = 0; i < maxcol; i++) {
							initial1 = initial1 + transfer;
							movement--;
							if (movement == 0) {
								break;
							}
						}
					}
					maxcol = maxcol - 1;
					maxrow = maxrow - 1;
					transfer *= -1;
					if (movement != 0) {
						for (i = 0; i < maxrow; i++) {
							initial1 = initial1 + (col*transfer);
							movement--;
							if (movement == 0) {
								break;
							}
						}
					}
					else if (movement == 0) {
						fprintf(output_fp, "%d\n", initial1);
						break;
					}
				}
				break;
			}
		}
	}
	fclose(input_fp);
	fclose(output_fp);
}