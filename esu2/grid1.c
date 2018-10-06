#include<stdio.h>


int main() {
	FILE *input_fp, *output_fp;
	if ((input_fp = fopen("grid1.inp", "rt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "grid1.inp");
	}
	if ((output_fp = fopen("grid1.out", "wt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "grid1.out");
	}
	int num = 0;
	int row = 0, col = 0;
	int type = 0;
	int startpoint = 0;
	int movement = 0;
	int i = 0;
	int a = 0;
	int value1 = 0;
	int value2 = 0;
	int count = 1;
	int result = 0;
	fscanf(input_fp, "%d\n", &num);
	for (num; num > 0; num--) {
		fscanf(input_fp, "%d %d %d %d %d\n", &row, &col, &type, &startpoint, &movement);
		if (type == 1) {
			switch (startpoint)
			{
			case 1:
				value1 = 1;
				a = movement / col;
				i = movement%col;
				if (a % 2 != 0) {
					if (i == 0) {
						a = a - 1;
						i = col-1;
						result = value1 + a*col + i;
						fprintf(output_fp, "%d\n", result);
						a = 0;
						i = 0;
						result = 0;
						value1 = 0;
						break;
					}
					else {
						result = value1 + (a*col) + (col - i);
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
				}
				else if (a % 2 == 0) {
					if (i == 0) {
						result = value1 + ((a - 1)*col) + i;
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
					else {
						result = value1 + (a*col) + (i - 1);
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
				}
			case 2:
				value1 = col;
				a = movement / col;
				i = movement%col;
				if (a % 2 != 0) {
					if (i == 0) {
						a = a - 1;
						i = col - 1;
						result = value1 + (a*col) - i;
						fprintf(output_fp, "%d\n", result);
						a = 0;
						i = 0;
						result = 0;
						break;
					}
					else {
						result = value1 + (a*col) - (col - i);
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
				}
				else if (a % 2 == 0) {
					if (i == 0) {
						result = value1 + ((a-1)*col) - i ;
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
					else {
						result = value1 + (a*col) - (i - 1);
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
				}
			case 3:
				value1 = row*col;
				a = movement / col;
				i = movement%col;
				if (a % 2 != 0) {
					if (i == 0) {
						a = a - 1;
						i = col - 1;
						result = value1 - (a*col) - i;
						fprintf(output_fp, "%d\n", result);
						break;
					}
					else {
						result = value1 - (a*col) - (col - i);
						fprintf(output_fp, "%d\n", result);
						break;
					}
				}
				else if (a % 2 == 0) {
					if (i == 0) {
						result = value1 - ((a - 1)*col) - i;
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
					else {
						result = value1 - (a*col) - (i - 1);
						fprintf(output_fp, "%d\n", result);
						break;
					}
				}
			case 4:
				value1 = (row*col + 1) - col;
				a = movement / col;
				i = movement%col;
				if (a % 2 != 0) {
					if (i == 0) {
						a = a - 1;
						i = col - i;
						result = value1 - (a*col) + (i-1);
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
					else {
						result = value1 - (a *col) + (col - i);
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
				}
				else if (a % 2 == 0) {
					if (i == 0) {
						result = value1 - ((a-1)*col) + i;
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
					else {
						result = value1 - (a*col) + (i - 1);
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
				}
			}
		}
		else if(type==2){
			switch (startpoint)
			{
			case 1:
				value1 = 1;
				a = movement / row;
				i = movement%row;
				if (a % 2 != 0) {
					if (i == 0) {
						result = value1 + (a - 1) + (col*(row - 1));
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
					else {
						result = value1 + a + (col*(row - i));
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}					
				}
				else if (a % 2 == 0) {
					if (i == 0) {
						result = value1 + (a - 1) + (col*i);
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
					else {
						result = value1 + a + (col*(i - 1));
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
				}
			case 2:
				value1 = col;
				a = movement / row;
				i = movement%row;
				if (a % 2 != 0) {
					if (i == 0) {
						a = a - 1;
						i = row - 1;
						result = value1 - (a - 1) + ((col*i) - 1);
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
					else {
						result = value1 - a + (col*(row - i));
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
				}
				else if (a % 2 == 0) {
					if (i == 0) {
						result = value1 - (a-1) + (col*i);
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
					else {
						result = value1 - a + (col*(i - 1));
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
				}
			case 3:
				value1 = row*col;
				a = movement / row;
				i = movement%row;
				if (a % 2 != 0) {
					if (i == 0) {
						a = a - 1;
						i = row - 1;
						result = value1 - a - (col*i);
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
					else {
						result = value1 - a - (col*(row - i));
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
				}
				else if (a % 2 == 0) {
					if (i == 0) {
						result = value1 - (a-1) - (col*i);
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
					else {
						result = value1 - a - (col*(i - 1));
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
				}
			case 4:
				value1 = ((row*col)+1) - col;
				a = movement / row;
				i = movement%row;
				
				if (a % 2 != 0) {
					if (i == 0) {
						a = a - 1;
						i = row - 1;
						value1 = value1+a - (i*col);
						fprintf(output_fp, "%d\n", value1);
						break;
					}
					else {
						value1 = value1 + a - (col*(row - i));
						fprintf(output_fp, "%d\n", value1);
						break;
					}
				}
				else if (a % 2 == 0) {
					if (i == 0) {
						result = value1 + (a - 1) - (col*i);
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
					else {
						result = value1 + a - (col*(i - 1));
						fprintf(output_fp, "%d\n", result);
						result = 0;
						break;
					}
				}
			}
		}
	}
	fclose(input_fp);
	fclose(output_fp);
}